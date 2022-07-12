/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:56:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/12 19:41:42 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void static	firstchild(t_piper *piper, char **argv, char **envp)
{
	if (piper->inflag)
		exit(1);
	close(piper->fd[0]);
	dup2(piper->fd[1], 1);
	close(piper->fd[1]);
	if (!piper->hereflag)
	{
		dup2(piper->infd, 0);
		close(piper->infd);
		piper->cmdpath = commander(piper, argv, 2);
	}
	else
		piper->cmdpath = commander(piper, argv, 3);
	if (!piper->cmdpath)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[2], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	if (execve(piper->cmdpath, piper->currcmd, envp) < 0)
		errxit("Execve error: command not found.\n");
}

void static	lastchild(t_piper *piper, char **argv, char **envp)
{
	waitpid(piper->childid[0], NULL, 0);
	piper->cmdpath = commander(piper, argv, 4);
	if (!piper->cmdpath)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(argv[3], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd("command not found\n", 2);
		exit(127);
	}
	close(piper->fd[1]);
	dup2(piper->fd[0], 0);
	close(piper->fd[0]);
	dup2(piper->outfd, 1);
	close(piper->outfd);
	if (execve(piper->cmdpath, piper->currcmd, envp) < 0)
		errxit("Execve error: command not found.\n");
}

void static	parent(t_piper *piper)
{
	int	exitstatus;

	close(piper->fd[0]);
	close(piper->fd[1]);
	waitpid(piper->childid[0], NULL, 0);
	waitpid(piper->childid[1], &exitstatus, 0);
	if (WIFEXITED(exitstatus))
		exit(WEXITSTATUS(exitstatus));
	exit(1);
}

void	pipex(t_piper *piper, char **argv, char **envp)
{
	piper->bustdin = dup(0);
	piper->bustdout = dup(1);
	piper->childid[0] = fork();
	if (piper->childid[0] < 0)
		errxit("Failed to child up :(\n");
	if (!piper->childid[0])
		firstchild(piper, argv, envp);
	piper->childid[1] = fork();
	if (piper->childid[1] < 0)
		errxit("Failed to have a second kid D:\n");
	if (!piper->childid[1])
		lastchild(piper, argv, envp);
	parent(piper);
}
