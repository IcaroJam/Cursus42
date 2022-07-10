/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:56:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/10 12:50:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char static	*commander(t_piper *piper, char **argv, int childpos)
{
	char	*temp;
	char	*ret;

	piper->currcmd = ft_split(argv[childpos], ' ');
	if (!piper->currcmd)
		errxit("Error while retrieving command arguments.");
	while (*piper->paths)
	{
		temp = ft_strjoin(*piper->paths, "/");
		ret = ft_strjoin(temp, piper->currcmd[0]);
		if (!ret)
			return (NULL);
		if (!access(ret, 0))
			return (ret);
		free(temp);
		free(ret);
		piper->paths++;
	}
	return (NULL);
}

void static	firstchild(t_piper *piper, char **argv)
{
	piper->cmdpath = commander(piper, argv, 2);
	if (!piper->cmdpath)
		errxit("Couldn't build command path.");
	close(piper->fd[0]);
	dup2(piper->fd[1], 1);
	close(piper->fd[1]);
	dup2(piper->infd, 0);
	close(piper->infd);
	if (execve(piper->cmdpath, argv, NULL) < 0)
	{
		dup2(1, piper->bustdout);
		errxit("Couldn't execute/find the command.");
	}
}

void static	lastchild(t_piper *piper, char **argv)
{
	//
	waitpid(piper->childid[0], NULL, 0);
	piper->cmdpath = commander(piper, argv, 3);
	if (!piper->cmdpath)
		errxit("Couldn't build command path.");
	close(piper->fd[1]);
	dup2(piper->fd[0], 0);
	close(piper->fd[0]);
	dup2(piper->outfd, 1);
	close(piper->outfd);
	if (execve(piper->cmdpath, argv, NULL) < 0)
	{
		dup2(1, piper->bustdout);
		errxit("Couldn't execute/find the command.");
	}
}

void static	parent(t_piper *piper)
{
	close(piper->fd[0]);
	close(piper->fd[1]);
	waitpid(piper->childid[0], NULL, 0);
	waitpid(piper->childid[1], NULL, 0);
}

void	pipex(t_piper *piper, char **argv)
{
	piper->bustdin = dup(0);
	piper->bustdout = dup(1);
	piper->childid[0] = fork();
	if (piper->childid[0] < 0)
		errxit("Failed to child up :(");
	if (!piper->childid[0])
		firstchild(piper, argv);
	piper->childid[1] = fork();
	if (piper->childid[1] < 0)
		errxit("Failed to have a second kid D:");
	if (!piper->childid[1])
		lastchild(piper, argv);
	parent(piper);
}
