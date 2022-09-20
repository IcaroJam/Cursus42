/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 10:57:51 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/20 10:02:35 by phijano-         ###   ########.fr       */
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

typedef struct s_process
{
	int	fd_in;
	int	fd_out;
	int	pid;
	int	in_fd_pipex[2];
	int	out_fd_pipex[2];
	int	error;
}	t_process;

t_parsing	*parse_line(char *line);
char		**tokenize_line(char *line);
void		free_tables(t_parsing *cts);
void		INT_handler(int sig);
void		QUIT_handler(int sig);
int			ft_has_path(char *cmd);
char		**ft_get_path(char **envp);
void		ft_executor(t_parsing *task, char **envp);
int			ft_check_built(t_parsing task, char **envp, t_process process);
void		ft_execute(t_process *process, char **cmd, char **envp);
int			ft_exit_status(int status);
int			ft_exit_code(int status);
#endif
