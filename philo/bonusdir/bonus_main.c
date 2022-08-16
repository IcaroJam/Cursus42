/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:02:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/16 19:29:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	philogenesis(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nop)
	{
		prg->phls[i].isdead = 0;
		prg->phls[i].ticketback = prg;
		prg->phls[i].timeseaten = 0;
		prg->phls[i].lstmealtime = 0;
		prg->phls[i].id = i + 1;
		i++;
	}
}

static int	philoprocessor(t_prg *prg, int i)
{
	prg->phls[i].pid = fork();
	if (prg->phls[i].pid < 0)
	{
		printf("Cyberphilosopher %d failed to exist.\n", prg->phls[i].id);
		return (1);
	}
	if (!prg->phls[i].pid)
		sophicroutine(prg, i);
	return (0);
}

static int	philinit(t_prg *prg)
{
	int	i;

	prg->phls = malloc(sizeof(t_philosopher) * prg->nop);
	if (!prg->phls)
	{
		printf("Not enough room for those thicc philobois.\n");
		return (1);
	}
	philogenesis(prg);
	prg->starttime = mstime();
	i = 0;
	while (i < prg->nop)
		if (philoprocessor(prg, i++))
			return (1);
	return (0);
}

static void	worldender(t_prg *prg)
{
	free(prg->phls);
	sem_close(prg->forks);
	sem_close(prg->log);
}

int	main(int argc, char **argv)
{
	t_prg	prg;

	if (inputhandler(argc, argv, &prg))
		return (1);
	sem_unlink("/fork_sem");
	sem_unlink("/log_sem");
	prg.forks = sem_open("/fork_sem", O_CREAT, 0644, prg.nop);
	prg.log = sem_open("/log_sem", O_CREAT, 0644, 1);
	if (philinit(&prg))
	{
		worldender(&prg);
		return (1);
	}
	waitpid(-1, &prg.notepmeflag, 0);
	while (--prg.nop > -1)
		kill(prg.phls[prg.nop].pid, 1);
	worldender(&prg);
	return (0);
}
