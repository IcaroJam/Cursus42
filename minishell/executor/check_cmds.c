/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmds.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 11:48:09 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/23 13:41:30 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_arg_error(char *s, int error)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(s, 2);
	if (error == 0)
		ft_putstr_fd(": No such file or directory\n", 2);
	else
		ft_putstr_fd(": command not found\n", 2);
}

void	ft_check_cmd(char **path, char *cmd)
{
	int		count;
	int		exist;
	char	*path_cmd;

	count = -1;
	exist = 0;
	if (access(cmd, F_OK) != -1)
		exist = 1;
	while (path[++count] && exist == 0)
	{
		path_cmd = ft_strjoin(path[count], cmd);
		if (access(path_cmd, F_OK) != -1)
			exist = 1;
		free(path_cmd);
	}
	if (exist == 0)
		ft_arg_error(cmd, 1);
}

int	ft_check_files(char **files, int ins_outs, int *iflgs)
{
	int	f1;
	int	count;
	int	error;

	error = 0;
	count = -1;
	while (files[++count])
	{
		if (ins_outs == 0)
		{
			if (!iflgs[count])
				f1 = open(files[count], O_RDONLY);
		}
		else
			f1 = open(files[count], O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (f1 < 0)
		{
			ft_arg_error(files[count], 0);
			error = 1;
			break ;
		}
		close(f1);
	}
	return (error);
}

void	ft_check_cmds(t_parsing *task, char **envp)
{
	int		count;
	char	**path;

	count = -1;
	while (task[++count].cmndtable)
	{
		if (!ft_check_files(task[count].ins, 0, task[count].iflgs))
		{
			if (!ft_check_files(task[count].outs, 1, task[count].oflgs))
			{
				path = ft_get_path(envp);
				if (ft_strncmp(task[count].cmndtable[0], "exit", 5))
					ft_check_cmd(path, task[count].cmndtable[0]);
				free_cmndline(path);
			}
		}
	}
}
