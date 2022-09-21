/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:31:55 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/21 15:09:37 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void static	dochere(t_process *process, char *limit)
{
	char	temp[4096];
	int		readflag;
	char 	*file_here;//
	char	*tmp;//


	tmp = ft_itoa(process->here_doc);//
	file_here = ft_strjoin(tmp, "_here_doc.tmp");//
	free(tmp);//
	//process->fd_in = open("here_doc.tmp", O_CREAT | O_WRONLY | O_APPEND, 0644);
	process->fd_in = open(file_here, O_CREAT | O_WRONLY | O_APPEND, 0644);
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
	process->fd_in = open(file_here, O_RDONLY);
	free(file_here);
	if (process->fd_in < 0)
		perror("Error: ");
}

void ft_remove_here(int count)
{
	char *file;
	char *tmp;

	while (count > 0)
	{
		tmp = ft_itoa(count--);
		file = ft_strjoin(tmp, "_here_doc.tmp");
		free(tmp);
		unlink(file);
		free(file);
	}
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
			{
				process->here_doc++;
				dochere(process, ins[count]);
			}
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

void	ft_set_fd_out(t_process *process, char **outs, int *oflgs)
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
			if (oflgs[count])
			{
				process->fd_out = open(outs[count], O_CREAT | O_WRONLY | O_APPEND, 0644);
			//	process->fd_out = open(outs[count], O_WRONLY | O_CREAT | O_APPEND, S_IRWXU);//comprobar flags
				ft_putstr_fd("modo append??\n" , 1);
			}
			else
			{
				process->fd_out = open(outs[count], O_WRONLY | O_CREAT
					| O_TRUNC | O_APPEND, S_IRWXU);//comprobar flags
				ft_putstr_fd("modo truncate\n",1);
			}
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
	process->here_doc = 0;
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
			ft_set_fd_out(&process, task[count].outs, task[count].oflgs);
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
	if (process.here_doc > 0)
	{
		ft_putstr_fd("deleting *here_doc.temp files\n", 1);//
		ft_remove_here(process.here_doc);
	}
	ft_putstr_fd("executor finished\n", 1);//borrar
}

	//de todas las salidas tiene que guardar en la ultima
	//pero tiene que crear los archivos de todas las salidas anteriores y machachar lo que tengan si estan creados (se quedan vacios)
	//si ademas depues de las salidas a ficheros hay un pipex no se guarda en el pipex se queda vacio
