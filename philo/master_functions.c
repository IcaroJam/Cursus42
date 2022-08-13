/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:27:43 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/13 13:56:51 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void static	consolelog(t_prg *prg, char *msg, int tstmp, int id)
{
	pthread_mutex_lock(&prg->log);
	if (!prg->philodeath)
		printf(msg, tstmp, id);
	pthread_mutex_unlock(&prg->log);
}

void static	munchtime(t_prg *prg, t_philosopher *cphl)
{
	pthread_mutex_lock(&prg->forks[cphl->leftfork]);
	if (!prg->philodeath)
		consolelog(prg, "%dms %d has taken a fork\n", timesince(prg), cphl->id);
	pthread_mutex_lock(&prg->forks[cphl->rightfork]);
	if (!prg->philodeath)
		consolelog(prg, "%dms %d has taken a fork\n", timesince(prg), cphl->id);
	if (!prg->philodeath)
	{
		consolelog(prg, "%dms %d is eating\n", timesince(prg), cphl->id);
		cphl->timeseaten++;
		cphl->lstmealtime = timesince(prg);
	}
	if (!prg->philodeath)
		usleep(1000 * prg->tte);
	pthread_mutex_unlock(&prg->forks[cphl->leftfork]);
	pthread_mutex_unlock(&prg->forks[cphl->rightfork]);
}

void	*sofic_routine(void *thelot)
{
	t_prg			*prg;
	t_philosopher	*cphl;

	cphl = thelot;
	prg = cphl->ticketback;
	cphl->leftfork = cphl->id - 1;
	cphl->rightfork = cphl->id;
	if (cphl->rightfork == prg->nop)
		cphl->rightfork = 0;
	if (cphl->id % 2)
		usleep(250);
	while (!prg->philodeath)
	{
		if (!prg->philodeath)
			munchtime(prg, cphl);
		if (!prg->philodeath)
			consolelog(prg, "%dms %d is sleeping\n", timesince(prg), cphl->id);
		if (!prg->philodeath)
			usleep(1000 * prg->tts);
		if (!prg->philodeath)
			consolelog(prg, "%dms %d is thinking\n", timesince(prg), cphl->id);
	}
	return (NULL);
}

void static	omnichecker(t_prg *prg, int i)
{
	if (timesince(prg) - prg->phls[i].lstmealtime > prg->ttd)
	{
		prg->philodeath = 1;
		printf("%dms %d died\n", timesince(prg), prg->phls[i].id);
		return ;
	}
	if (prg->phls[i].timeseaten > prg->notepme)
		prg->notepmeflag++;
}

void	*everwatcher(void *wholething)
{
	t_prg	*prg;
	int		phildex;

	prg = wholething;
	while (!prg->philodeath)
	{
		phildex = 0;
		prg->notepmeflag = 0;
		while (phildex < prg->nop && !prg->philodeath)
			omnichecker(prg, phildex++);
		if (prg->notepme > -1 && prg->notepmeflag == prg->nop)
		{
			prg->philodeath = 1;
			printf("All philobois ate %d times.\n", prg->notepme);
		}
	}
	phildex = 0;
	while (phildex < prg->nop)
		pthread_join(prg->phls[phildex++].philo, NULL);
	return (NULL);
}
