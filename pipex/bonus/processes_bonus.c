/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 10:56:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/13 17:08:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void static	parent(t_piper *piper)
{
	int	exitstatus;

	close(piper->fd[0]);
	close(piper->fd[1]);
	if (piper->hereflag)
	{
		waitpid(piper->childid[0], NULL, 0);
		close(piper->infd);
		unlink("here_doc.tmp");
	}
	waitpid(piper->childid[piper->currchildpos - 1], &exitstatus, 0);
	if (WIFEXITED(exitstatus))
		exit(WEXITSTATUS(exitstatus));
	exit(1);
}

void static	forker(t_piper *piper, int childflag, char **argv, char **envp)
{
	piper->childid[piper->currchildpos] = fork();
	if (piper->childid[piper->currchildpos] < 0)
	{
		ft_putstr_fd("Fork failed on child no.: ", 2);
		ft_putstr_fd(ft_itoa(piper->currchildpos), 2);
		errxit(".\n");
	}
	if (!piper->childid[piper->currchildpos])
	{
		if (childflag < 0)
			firstchild(piper, argv, envp);
		else if (!childflag)
			middlechild(piper, argv, envp);
		else
			lastchild(piper, argv, envp);
	}
	piper->currchildpos++;
}

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

void	pipex(t_piper *piper, int argc, char **argv, char **envp)
{
	piper->bustdin = dup(0);
	piper->bustdout = dup(1);
	piper->childid = malloc(sizeof(int) * (argc - (3 + piper->hereflag)));
	if (!piper->childid)
		errxit("Couldn't create childid array.");
	piper->currchildpos = 0;
	argc -= 4 + piper->hereflag;
	if (piper->hereflag)
		dochere(piper);
	forker(piper, -1, argv, envp);
	while (argc-- > 1)
	{
		close(piper->fd[1]);
		piper->oldpipe = dup(piper->fd[0]);
		close(piper->fd[0]);
		if (pipe(piper->fd) < 0)
			errxit("Failed to create a pipe.\n");
		forker(piper, 0, argv, envp);
	}
	forker(piper, 1, argv, envp);
	parent(piper);
}
