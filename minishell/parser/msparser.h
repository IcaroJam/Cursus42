/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msparser.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:09:55 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/07 17:04:18 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MSPARSER_H
# define MSPARSER_H

typedef struct s_lexutil
{
	const char	*line;
	int			lnoff;
}	t_lexutil;

// Utilities for the lexing stage:
int		count_isspace(const char *line);
int		count_words(const char *line);
int		handle_quotes(const char *line, const char flag);
int		handle_redir(const char *line);
int		isredir(const char c);
void	free_cmndline(char **cmndline);

#endif
