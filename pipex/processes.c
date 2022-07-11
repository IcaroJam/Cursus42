/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:56:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/11 11:39:19 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void static	firstchild(t_piper *piper, char **argv, char **envp)
{
	if (piper->inflag)
		exit(1);
	piper->cmdpath = commander(piper, argv, 2);
	if (!piper->cmdpath)
		errxit("Couldn't build command path: command not found.\n");
	close(piper->fd[0]);
	dup2(piper->fd[1], 1);
	close(piper->fd[1]);
	dup2(piper->infd, 0);
	close(piper->infd);
	if (execve(piper->cmdpath, piper->currcmd, envp) < 0)
		errxit("Execve error: command not found.\n");
}

void static	lastchild(t_piper *piper, char **argv, char **envp)
{
	waitpid(piper->childid[0], NULL, 0);
	piper->cmdpath = commander(piper, argv, 3);
	if (!piper->cmdpath)
		errxit("Couldn't build command path: command not found.\n");
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
	close(piper->fd[0]);
	close(piper->fd[1]);
	waitpid(piper->childid[0], NULL, 0);
	waitpid(piper->childid[1], NULL, 0);
	exit(0);
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
