/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 13:31:55 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/16 11:23:39 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int static	ft_path_cmd(char **cmd, char **envp)
{
	int		cmd_exist;

	cmd_exist = 0;
	if (access(cmd[0], F_OK) != -1)
	{
		cmd_exist = 1;
		ft_putstr_fd(cmd[0], 1);
		if (access(cmd[0], X_OK) == -1)
			exit(0);
		else if (execve(cmd[0], cmd, envp) == -1)
			exit(1);
	}
	return (cmd_exist);
}

void static	ft_do_cmd(char **path, char **cmd, char **envp)
{
	int		count;
	char	*path_cmd;
	int		cmd_exist;
	
	cmd_exist = ft_path_cmd(cmd, envp);
	count = -1;
	while (path[++count])
	{
		path_cmd = ft_strjoin(path[count], cmd[0]);
		if (access(path_cmd, F_OK) != -1)
		{
			cmd_exist = 1;
			if (execve(path_cmd, cmd, envp) == -1)
				exit(1);
		}
		free(path_cmd);
	}
	if (cmd_exist == 0)
		exit(127);
}

typedef struct s_process //poner en minishell.h cuando este terminada
{
	int	fd_in;
	int	fd_out;
	int	pid;
//	int fd_pipex[2];
	int in_fd_pipex[2];
	int out_fd_pipex[2];
	int error;
}	t_process;


void	ft_execute(t_process *process, char **cmd, char **envp) // abrir y cerrar fds
{
	char	**path;

//	perror("Execute");//borrar
	//
	if (process->in_fd_pipex[1] > 0)
		close(process->in_fd_pipex[1]);
	if (process->out_fd_pipex[0] > 0)
		close(process->out_fd_pipex[0]);
	//
	dup2(process->fd_in, 0);
//	perror("FDS: ");//
	close(process->fd_in);
	dup2(process->fd_out, 1);
//	perror("FDS: ");//
	close(process->fd_out);
	path = ft_get_path(envp);
	ft_do_cmd(path, cmd, envp);
	free(path);
}

//de todas las entradas tiene que quedarse con la ultima
//pero si una entrada no existe tiene que terminar la ejecucion y sacar error
void	ft_set_fd_in(t_process *process, char **ins)
{
	int count;
	ft_putstr_fd("fd_in start\n", 1);//borrar
//	if (process->fd_pipex[0] > 0)
//		process->fd_in = process->fd_pipex[0];
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
//
	process->error = 0;
	count = -1;
	if (ins)
	{
		while (ins[++count])
		{
			process->fd_in = open(ins[count], O_RDONLY);
			if (process->fd_in == -1)
			{
				process->error = 1;
				break;
			}
		}
	}
	ft_putstr_fd("fd_in set\n", 1);//borrar

}

void	ft_set_fd_out(t_process *process, char **outs)
{
	int count;
	ft_putstr_fd("fd_out start\n", 1);//borrar
	pipe(process->out_fd_pipex);
	process->fd_out = process->out_fd_pipex[1];
	count = -1;
	if (outs)
	{
		while (outs[++count])
		{
			process->fd_out = open(outs[count], O_WRONLY | O_CREAT
				| O_TRUNC | O_APPEND, S_IRWXU);	//comprobar flags
			if (process->fd_out == -1)
			{
				process->error = 1;
				break;
			}
		}
	}
	ft_putstr_fd("fd_out set\n", 1);//borrar

}

void	ft_init_process(t_process *process)
{
	//process->fd_pipex[0] = -1;
	//process->fd_pipex[1] = -1;
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
	ft_putstr_fd("esperando:", 1);
	waitpid(pid, &status, 0);
	ft_putstr_fd("hecho", 1);
	if (ft_exit_status(status))
		error = ft_exit_code(status);
	return (error); //averiguar donde ponemos el valor de exit
}

void	ft_executor(t_task *task, char **envp)
{
	t_process	process;
	int 		count;

	ft_init_process(&process);
	count = -1;
	ft_putstr_fd("executor start\n", 1);//borrar
	while (task[++count].cmds)
	{
		if (count == 0 && !task[count].ins)
			process.fd_in = dup(0);
		else
			ft_set_fd_in(&process, task[count].ins);
		// si hay entrada que no existe sacar error y no ejecutar lo demas 
		if (!task[count + 1].cmds)
			process.fd_out = dup(1);
		else
			ft_set_fd_out(&process, task[count].outs);
		//if (!ft_check_built(task[count]))//comprobar
		process.pid = fork(); //Arreglar! si el comando es un built debe ejecutarlo el padre !No hacer fork
		//perror("???");
		if (process.pid == -1)
			perror("Error fork\n");
		else if (process.pid == 0)
			//perror("???");
			ft_execute(&process, task[count].cmds, envp);
	}
	close(process.in_fd_pipex[0]);
	close(process.in_fd_pipex[1]);
	ft_father(process.pid);
	ft_putstr_fd("executor finished\n", 1);//borrar
}

	//de todas las salidas tiene que guardar en la ultima
	//pero tiene que crear los archivos de todas las salidas anteriores y machachar lo que tengan si estan creados (se quedan vacios)
	//si ademas depues de las salidas a ficheros hay un pipex no se guarda en el pipex se queda vacio

/*
void	ft_executor(t_task task, char **envp)
{
	int	pid;
	int count;
	int tmp_in;
	int tmp_out;
	int fd_in;
	int fd_out;
	int fd_pipe[2];

	ft_putstr_fd("start executor function\n", 1);
	tmp_in = dup(0);
	tmp_out = dup(1);
	//if (task.ins[0])
	if (task.ins) //tabla de inputs no creada aun, cuando este cambiar if
		fd_in = open(task.ins[0][0], O_RDONLY);
	else
		fd_in = dup(tmp_in);
	count = -1;
	ft_putstr_fd("fd first command\n", 1);
	while(task.cmds[++count])
	{
		dup2(fd_in, 0);
		close(fd_in);
		if (!task.cmds[count + 1])
		{
			//if (task.outs[count])
			if (task.outs) // tabla outs no creada aun
				fd_out = open(task.outs[count][0], O_WRONLY | O_CREAT
				| O_TRUNC | O_APPEND, S_IRWXU);
			else
				fd_out = dup(tmp_out);
		}
		else
		{
			pipe(fd_pipe);
			fd_in = fd_pipe[0];
			fd_out = fd_pipe[1];
		}
		dup2(fd_out, 1);
		close(fd_out);
		pid = fork();
		if (pid == -1)
			perror("Error");
		else if (pid == 0)
		{
			ft_execute(task.cmds[count], envp);
			exit(1);
		}
	}
	dup2(tmp_in, 0);
	dup2(tmp_out, 1);
	close(tmp_in);
	close(tmp_out);
	waitpid(pid, NULL, 0);
}
*/
