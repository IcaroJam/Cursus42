/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:57:51 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/20 11:43:50 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "libft/libft.h"

// Parser stuff.

typedef struct s_parsing
{
	char	**cmndtable;
	char	**ins;
	int		*iflgs;
	char	**outs;
	int		*oflgs;
	int		islast;
}	t_parsing;

t_parsing	*parse_line(char *line);
char		**tokenize_line(char *line);
void		free_tables(t_parsing *cts);

// Builtins.

int			ms_echo(t_parsing cts);
int			ms_pwd(void);
int			ms_env(char **env);
int			ms_exit(t_parsing *cts, char *cmndline);

#endif
