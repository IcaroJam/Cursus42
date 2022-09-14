/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msparser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:09:55 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/14 11:47:02 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSPARSER_H
# define MSPARSER_H

# include "../minishell.h"

// Utilities for the lexing stage:
int		count_isspace(const char *line);
int		count_words(const char *line);
int		handle_quotes(const char *line, const char flag);
int		handle_redir(const char *line);
int		process_word(const char *line);
int		isredir(const char c);
void	free_cmndline(char **cmndline);
int		check_redirerr(const char **tkns);
void	set_tablelast(t_parsing *cts, const int i);
int		stff_aid(char **chain, const char **tkns, int *qtty);
int		expand_quotes(t_parsing *cts);

#endif
