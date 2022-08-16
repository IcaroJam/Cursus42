/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:56:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/16 19:20:35 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bonus_philosophers.h"

static void	munchtime(t_prg *prg, t_philosopher *cphl)
{
	sem_wait(prg->forks);
	printf("%dms %d has taken a fork\n", timesince(prg), cphl->id);
	sem_wait(prg->forks);
	printf("%dms %d has taken a fork\n", timesince(prg), cphl->id);
	cphl->lstmealtime = timesince(prg);
	printf("%dms %d is eating\n", cphl->lstmealtime, cphl->id);
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
	while (!prg->phls[phid].isdead)
	{
		munchtime(prg, &prg->phls[phid]);
		printf("%dms %d is sleeping\n", timesince(prg), prg->phls[phid].id);
		phisleep(prg, prg->tts);
		printf("%dms %d is thinking\n", timesince(prg), prg->phls[phid].id);
	}
	pthread_join(statuschecker, NULL);
	exit(1);
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
			printf("%dms %d died\n", timesince(prg), cphl->id);
			cphl->isdead = 1;
			exit(1);
		}
	}
	return (NULL);
}
