/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:57:51 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/19 11:49:24 by ntamayo-         ###   ########.fr       */
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
	char	**outs;
	int		islast;
}	t_parsing;

t_parsing	*parse_line(char *line);
char		**tokenize_line(char *line);
void		free_tables(t_parsing *cts);

// Builtins.



#endif
