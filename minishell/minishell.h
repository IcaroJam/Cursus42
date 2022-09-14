#ifndef MINISHELL_H
 #define MINISHELL_H

#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>
//# include <unistd.h>
//# include <errno.h>
#include <fcntl.h>
#include <sys/ioctl.h>

# define PTH "PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/sbin:/usr/sbin:/sbin"

typedef struct s_task
{
	char **cmds;
	char **ins;
	char **outs;
}	t_task;

void	INT_handler();
void	QUIT_handler();
int		ft_has_path(char *cmd);
char	**ft_get_path(char **envp);
void	ft_executor(t_task *task, char **envp);
int		ft_exit_status(int status);
int		ft_exit_code(int status);

#endif
