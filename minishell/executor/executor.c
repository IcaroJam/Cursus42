/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:31:55 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/23 12:41:47 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_init_process(t_process *process)
{
	process->here_doc = 0;
	process->in_fd_pipex[0] = -1;
	process->in_fd_pipex[1] = -1;
	process->out_fd_pipex[0] = -1;
	process->out_fd_pipex[1] = -1;
	process->last_process = -1;// 0 normal, 1 builtin
	process->exit_code = -1;
}

void	ft_father(t_process process)
{
	int		status;
	//int		error;

	if (process.out_fd_pipex[0] >= 0)
		close(process.out_fd_pipex[0]);
	if (process.here_doc > 0)
	{
		ft_putstr_fd("deleting *here_doc.temp files\n", 1);//
		ft_remove_here(process.here_doc);
	}
//	error = 0;
	ft_putstr_fd("waiting...\n", 1);//borrar
	waitpid(process.pid, &status, 0);
	ft_putstr_fd("done\n", 1);//borrar
	if (process.last_process)
		envupdate("?", ft_itoa(process.exit_code));
		//	error = process.exit_code;
	else if (ft_exit_status(status))
		envupdate("?", ft_itoa(ft_exit_code(status)));	
	//	error = ft_exit_code(status);
	//return (error); //averiguar donde ponemos el valor de exit
}

void	ft_executor(t_parsing *task, char **envp)
{
	t_process	process;
	int			count;

	ft_init_process(&process);
	count = -1;
	ft_putstr_fd("executor start\n", 1);//borrar
	while (task[++count].cmndtable)
	{
		if (count == 0 && task[count].ins[0] == NULL)
		{
			process.fd_in = dup(0);
			ft_putstr_fd("fd_stdin_dup: ", 1);//
			ft_putnbr_fd(process.fd_in, 1);//
			ft_putstr_fd("\n", 1);//
		}	
		else
			ft_set_fd_in(&process, task[count].ins, task[count].iflgs);
		// si hay entrada que no existe sacar error y no ejecutar lo demas
		if (!task[count + 1].cmndtable && task[count].outs[0] == NULL)
		{
			process.fd_out = dup(1);
			ft_putstr_fd("fd_stdout_dup: ", 1);//
			ft_putnbr_fd(process.fd_out, 1);//
			ft_putstr_fd("\n", 1);//
		}
		else
			ft_set_fd_out(&process, task[count].outs, task[count].oflgs);
		process.last_process = ft_check_built(task[count], envp, &process);
		if (!process.last_process)
			process.pid = fork();
		if (process.pid == -1)
			perror("Error fork\n");
		else if (process.pid == 0)
			ft_execute(process, task[count].cmndtable, envp);
		else 
			ft_close_fds(process);
	}
	ft_father(process);//utilizer el retorno para poner el $?
	ft_putstr_fd("executor finished\n", 1);//borrar
}
