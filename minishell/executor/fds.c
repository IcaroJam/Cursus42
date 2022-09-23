/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fds.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 12:14:56 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/23 12:23:48 by phijano-         ###   ########.fr       */
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
	if (process->out_fd_pipex[0] >= 0)
	{
		process->in_fd_pipex[0] = process->out_fd_pipex[0];
		process->in_fd_pipex[1] = process->out_fd_pipex[1];
		process->fd_in = process->in_fd_pipex[0];
	}
	count = -1;
	if (ins)
	{
		while (ins[++count])
		{
			if (count > 0)
			{
				close(process->fd_in);
				ft_putstr_fd("closed fd_in de file father: ", 1);//
				ft_putnbr_fd(process->fd_in, 1);//
				ft_putstr_fd("\n", 1);//
			}
			if (iflgs[count])
			{
				process->here_doc++;
				dochere(process, ins[count]);
			}
			else
				process->fd_in = open(ins[count], O_RDONLY);
			if (process->fd_in == -1)
				break ;
		}
	}
	ft_putstr_fd("fd_in set\n", 1);//borrar
}

void	ft_set_fd_out(t_process *process, char **outs, int *oflgs)
{
	int	count;

	ft_putstr_fd("fd_out start\n", 1);//borrar
//	if (!outs)
//	{
		pipe(process->out_fd_pipex);
		process->fd_out = process->out_fd_pipex[1];
		ft_putstr_fd("created pipex: ", 1);//
		ft_putnbr_fd(process->out_fd_pipex[0], 1);//
		ft_putstr_fd(" ", 1);//
		ft_putnbr_fd(process->out_fd_pipex[1], 1);//
		ft_putstr_fd("\n", 1);//

//	}
//	else
	if (outs)
	{
		count = -1;
		while (outs[++count])
		{
			if (count > 0)
			{
				close(process->fd_out);
				ft_putstr_fd("closed fd_out de file father: ", 1);//
				ft_putnbr_fd(process->fd_out, 1);//
				ft_putstr_fd("\n", 1);//
			}
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
				break ;
		}
	}
	ft_putstr_fd("fd_out set\n", 1);//borrar
}

void ft_close_fds(t_process process)
{
	if (process.fd_in >= 0)
	{
		close(process.fd_in);
		ft_putstr_fd("closed fd_in father: ", 1);//
		ft_putnbr_fd(process.fd_in, 1);//
		ft_putstr_fd("\n", 1);//
	}
	if (process.fd_out >= 0 && process.fd_out)
	{
		close(process.fd_out);
		ft_putstr_fd("closed fd_out father: ", 1);//
		ft_putnbr_fd(process.fd_out, 1);//
		ft_putstr_fd("\n", 1);//
	}
	if (process.in_fd_pipex[0] >= 0 && process.in_fd_pipex[0] != process.fd_in)
	{
		close(process.in_fd_pipex[0]);
		ft_putstr_fd("closed fd_in_pipex_0 father: ", 1);//
		ft_putnbr_fd(process.in_fd_pipex[0], 1);//
		ft_putstr_fd("\n", 1);//
	}
/*
	if (process.in_fd_pipex[1] >= 0)
	{
		close(process.in_fd_pipex[1]);
		ft_putstr_fd("closed fd_in_pipex_1 father: ", 1);//
		ft_putnbr_fd(process.in_fd_pipex[1], 1);//
		ft_putstr_fd("\n", 1);//
	}
*/

/*
	if (process.out_fd_pipex[0] >= 0)
	{
		close(process.out_fd_pipex[0]);
		ft_putstr_fd("closed fd_out_pipex_0 father: ", 1);//
		ft_putnbr_fd(process.out_fd_pipex[0], 1);//
		ft_putstr_fd("\n", 1);//
	}
*/
	if (process.out_fd_pipex[1] >= 0 && process.out_fd_pipex[1] != process.fd_out && process.out_fd_pipex[1] != process.in_fd_pipex[1])
	{
		close(process.out_fd_pipex[1]);
		ft_putstr_fd("closed fd_out_pipex_1 father: ", 1);//
		ft_putnbr_fd(process.out_fd_pipex[1], 1);//
		ft_putstr_fd("\n", 1);//
	}
}
