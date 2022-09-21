/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:31:55 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/21 11:24:24 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

//Nestor heredoc
/*
void static	dochere(t_piper *piper)
{
	char	temp[4096];
	int		readflag;

	readflag = 1;
	while (readflag)
	{
		write(1, "pipex heredoc> ", 15);
		readflag = read(0, temp, 4096);
		if (!ft_strncmp(piper->herelim, temp, ft_strlen(piper->herelim))
			&& temp[ft_strlen(piper->herelim)] == '\n')
			break ;
		write(piper->infd, temp, readflag);
	}
	close(piper->infd);
	piper->infd = open("here_doc.tmp", O_RDONLY);
	if (piper->infd < 0)
		errxit("Failed to reopen tempfile.");
}
*/

void static	dochere(t_process *process, char *limit)
{
	char	temp[4096];
	int		readflag;

	process->fd_in = open("here_doc.tmp", O_CREAT | O_WRONLY | O_APPEND, 0644);
	readflag = 1;
	while (readflag)
	{
		ft_putstr_fd("minishell heredoc >" , 1);
		readflag = read(0, temp, 4096);
		if (!ft_strncmp(limit, temp, ft_strlen(limit))
			&& temp[ft_strlen(limit)] == '\n')
			break ;
		write(process->fd_in, temp, readflag);
	}
	close(process->fd_in);
	process->fd_in = open("here_doc.tmp", O_RDONLY);
	if (process->fd_in < 0)
		perror("Error: ");
}

void	ft_set_fd_in(t_process *process, char **ins, int *iflgs)
{
	int	count;

	ft_putstr_fd("fd_in start\n", 1);//borrar
	if (process->out_fd_pipex[0] > 0)
	{
		if (process->in_fd_pipex[0] > 0)
		{
			close(process->in_fd_pipex[0]);
			close(process->in_fd_pipex[1]);
		}
		process->in_fd_pipex[0] = process->out_fd_pipex[0];
		process->in_fd_pipex[1] = process->out_fd_pipex[0];
		process->fd_in = process->in_fd_pipex[0];
	}
	process->error = 0;
	count = -1;
	if (ins)
	{
		while (ins[++count])
		{
			if (iflgs[count])
				dochere(process, ins[count]);
			else
				process->fd_in = open(ins[count], O_RDONLY);
			if (process->fd_in == -1)
			{
				process->error = 1;
				break ;
			}
		}
	}
	ft_putstr_fd("fd_in set\n", 1);//borrar
}

void	ft_set_fd_out(t_process *process, char **outs)
{
	int	count;

	ft_putstr_fd("fd_out start\n", 1);//borrar
	pipe(process->out_fd_pipex);
	process->fd_out = process->out_fd_pipex[1];
	count = -1;
	if (outs)
	{
		while (outs[++count])
		{
			process->fd_out = open(outs[count], O_WRONLY | O_CREAT
					| O_TRUNC | O_APPEND, S_IRWXU);//comprobar flags
			if (process->fd_out == -1)
			{
				process->error = 1;
				break ;
			}
		}
	}
	ft_putstr_fd("fd_out set\n", 1);//borrar
}

void	ft_init_process(t_process *process)
{
	process->in_fd_pipex[0] = -1;
	process->in_fd_pipex[1] = -1;
	process->out_fd_pipex[0] = -1;
	process->out_fd_pipex[1] = -1;
	process->error = 0;
}

int	ft_father(int pid)
{
	int		status;
	int		error;

	error = 0;
	ft_putstr_fd("waiting...\n", 1);//borrar
	waitpid(pid, &status, 0);
	ft_putstr_fd("done\n", 1);//borrar
	if (ft_exit_status(status))
		error = ft_exit_code(status);
	return (error); //averiguar donde ponemos el valor de exit
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
			process.fd_in = dup(0);
		else
			ft_set_fd_in(&process, task[count].ins, task[count].iflgs);
		// si hay entrada que no existe sacar error y no ejecutar lo demas
		if (!task[count + 1].cmndtable && task[count].outs[0] == NULL)
			process.fd_out = dup(1);
		else
			ft_set_fd_out(&process, task[count].outs);
		if (!ft_check_built(task[count], envp, process))
			process.pid = fork();
		if (process.pid == -1)
			perror("Error fork\n");
		else if (process.pid == 0)
			ft_execute(&process, task[count].cmndtable, envp);
	}
	close(process.in_fd_pipex[0]);
	close(process.in_fd_pipex[1]);
	ft_father(process.pid);
	ft_putstr_fd("executor finished\n", 1);//borrar
}

	//de todas las salidas tiene que guardar en la ultima
	//pero tiene que crear los archivos de todas las salidas anteriores y machachar lo que tengan si estan creados (se quedan vacios)
	//si ademas depues de las salidas a ficheros hay un pipex no se guarda en el pipex se queda vacio
