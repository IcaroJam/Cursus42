/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:56:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/17 15:07:41 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	solog(t_prg *prg, const char *msg, int time, int id)
{
	sem_wait(prg->log);
	printf(msg, time, id);
	if (!prg->phls[id - 1].isdead)
		sem_post(prg->log);
}

static void	munchtime(t_prg *prg, t_philosopher *cphl)
{
	sem_wait(prg->forks);
	solog(prg, "%dms %d has taken a fork\n", timesince(prg), cphl->id);
	sem_wait(prg->forks);
	solog(prg, "%dms %d has taken a fork\n", timesince(prg), cphl->id);
	cphl->lstmealtime = timesince(prg);
	solog(prg, "%dms %d is eating\n", cphl->lstmealtime, cphl->id);
	cphl->timeseaten++;
	phisleep(prg, prg->tte);
	sem_post(prg->forks);
	sem_post(prg->forks);
}

void	sophicroutine(t_prg *prg, int phid)
{
	pthread_t	statuschecker;

	if (pthread_create(&statuschecker, NULL, overseer, &prg->phls[phid]))
	{
		printf("Failed to create watcher thread for philo %d\n", phid + 1);
		exit(1);
	}
	if (phid % 2)
		usleep(250);
	while (1)
	{
		munchtime(prg, &prg->phls[phid]);
		solog(prg, "%dms %d is sleeping\n", timesince(prg), prg->phls[phid].id);
		phisleep(prg, prg->tts);
		solog(prg, "%dms %d is thinking\n", timesince(prg), prg->phls[phid].id);
	}
}

void	*overseer(void *everything)
{
	t_philosopher	*cphl;
	t_prg			*prg;

	cphl = everything;
	prg = cphl->ticketback;
	while (!cphl->isdead)
	{
		if (timesince(prg) - cphl->lstmealtime > prg->ttd)
		{
			cphl->isdead = 1;
			solog(prg, "%dms %d died\n", timesince(prg), cphl->id);
			exit(1);
		}
		if (prg->notepme > -1 && cphl->timeseaten == prg->notepme)
		{
			cphl->isdead = 1;
			sem_post(prg->forks);
			sem_post(prg->forks);
			exit(0);
		}
	}
	return (NULL);
}
