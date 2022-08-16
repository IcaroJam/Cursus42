/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 11:56:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/16 13:38:54 by ntamayo-         ###   ########.fr       */
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
	if (phid % 2)
		usleep(250);
	while (1)
	{
		munchtime(prg, &prg->phls[phid]);
		printf("%dms %d is sleeping\n", timesince(prg), prg->phls[phid].id);
		phisleep(prg, prg->tts);
		printf("%dms %d is thinking\n", timesince(prg), prg->phls[phid].id);
	}
}

static void	philokill(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nop)
		kill(prg->phls[i].pid, 1);
}

void	overseer(t_prg *prg)
{
	int	i;

	while (1)
	{
		i = 0;
		prg->notepmeflag = 0;
		while (i < prg->nop)
		{
			if (timesince(prg) - prg->phls[i].lstmealtime > prg->ttd)
			{
				printf("%dms %d died\n", timesince(prg), prg->phls[i].id);
				break ;
			}
			if (prg->phls[i].timeseaten > prg->notepme)
				prg->notepmeflag++;
		}
		if (prg->notepmeflag > -1 && prg->notepmeflag == prg->nop)
		{
			printf("All philobois ate %d times.\n", prg->notepme);
			break ;
		}
	}
	philokill(prg);
}
