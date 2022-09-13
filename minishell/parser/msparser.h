/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msparser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:09:55 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/13 18:05:19 by ntamayo-         ###   ########.fr       */
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
int		stuff_cmnd(t_parsing *cts, const char **tkns, int *qtty);
int		stuff_ins(t_parsing *cts, const char **tkns, int *qtty);
int		stuff_outs(t_parsing *cts, const char **tkns, int *qtty);

#endif
