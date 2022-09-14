/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:45:57 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/06 12:51:09 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libminishell.h"

void	ft_path_cmd(char *cmd, char **cmd_args, char **envp) //intenta ejecutar comando con ruta especificada
{
	int	cmd_exist;

	cmd_exist = 0;
	if (access(cmd, F_OK) != -1)
	{
		cmd_exist = 1;
		if (access(fix_cmd, X_OK) == -1)
			exit(0);
		else if (execve(fix_cmd, cmd_args, envp) == -1)
			exit(1);
	}
	return (cmd_exist);
}

void	ft_do_cmd(char **path, char ***task, char **envp) 
{
	int		count;
	char	*path_cmd;
	int		cmd_exist;

	count = -1;
	cmd_exist = ft_path_cmd(task[2][0], task[2], envp)
	while (path[++count])									//intenta ejecutar el comando en las rutas del path
	{
		path_cmd = ft_strjoin(path[count], task[2][0]);
		if (access(path_cmd, F_OK) != -1)
		{
			cmd_exist = 1;
			if (execve(path_cmd, task[2], envp) == -1)
				exit(1);
		}
		free(path_cmd);
	}
	if (cmd_exist == 0)
		exit(127);
}

void ft_execute(char ***task, char **envp)
{
	char **path;

	path = ft_get_path(envp);
	ft_do_cmd(path, task, envp);
	free(path);
}

/*
void	ft_process(int *fd, char ***task, char **argv, char **envp)
{
	int		fd_infile;
	char	**path;

	close(fd[0]);
	fd_infile = open(argv[1], O_RDONLY);
	if (fd_infile == -1)
		exit(0);
	dup2(fd_infile, STDIN_FILENO);
	close(fd_infile);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);

	path = ft_get_path(envp);
	ft_do_cmd(path, task, envp);
	free(path);
}
*/
