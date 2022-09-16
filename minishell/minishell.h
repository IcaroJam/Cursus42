/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:57:51 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/16 13:28:37 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <sys/ioctl.h>

# define PTH "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin"

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
void		INT_handler();
void		QUIT_handler();
int			ft_has_path(char *cmd);
char		**ft_get_path(char **envp);
void		ft_executor(t_parsing *task, char **envp);
int			ft_exit_status(int status);
int			ft_exit_code(int status);
#endif
