/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   master_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 11:27:43 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/11 12:41:14 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	munchtime(t_prg *prg, t_philosopher *cphl)
{
	pthread_mutex_lock(&prg->forks[cphl->leftfork]);
	printf("%d %d has taken a fork\n", prg->starttime - mstime(), cphl->id);
	pthread_mutex_lock(&prg->forks[cphl->rightfork]);
	printf("%d %d has taken a fork\n", prg->starttime - mstime(), cphl->id);
	printf("%d %d is eating\n", prg->starttime - mstime(), cphl->id);
	usleep(1000 * prg->tte);
	cphl->timeseaten++;
	cphl->lstmealtime = prg->starttime - mstime();
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
	while (1)
	{
		printf("%d %d is thinking\n", prg->starttime - mstime(), cphl->id);
		munchtime(prg, cphl);
		printf("%d %d is sleeping\n", prg->starttime - mstime(), cphl->id);
		usleep(1000 * prg->tts);
	}
	return (NULL);
}

void	*everwatcher(void *wholething)
{
	t_prg	*prg;

	prg = wholething;
	return (NULL);
}
