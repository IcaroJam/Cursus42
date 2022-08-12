/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:02:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/12 12:10:08 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int static	utensilgenesis(t_prg *prg)
{
	int	i;

	i = 0;
	prg->phls = NULL;
	prg->forks = malloc(sizeof(pthread_mutex_t) * prg->nop);
	if (!prg->forks)
	{
		printf("Failed to allocate cupboard space for the forks.\n");
		return (1);
	}
	while (i < prg->nop)
	{
		if (pthread_mutex_init(&prg->forks[i], NULL))
		{
			printf("Fork %d was mind-bended into nothingness.\n", i);
			prg->nop = 0;
			while (prg->nop < i)
				pthread_mutex_destroy(&prg->forks[prg->nop++]);
			return (1);
		}
		i++;
	}
	return (0);
}

int static	philogenesis(t_prg *prg)
{
	int	i;

	i = 0;
	while (i < prg->nop)
	{
		prg->phls[i].ticketback = prg;
		prg->phls[i].timeseaten = 0;
		prg->phls[i].lstmealtime = -1;
		if (pthread_create(&prg->phls[i].philo, NULL, sofic_routine,
				&prg->phls[i]))
		{
			printf("Philosopher %d is unborn D:\n", i + 1);
			return (1);
		}
		prg->phls[i].id = i + 1;
		i++;
	}
	return (0);
}

int static	philinit(t_prg *prg)
{
	prg->phls = malloc(sizeof(t_philosopher) * prg->nop);
	if (!prg->phls)
	{
		printf("Not enough room for those thicc philobois.\n");
		return (1);
	}
	if (philogenesis(prg))
		return (1);
	if (pthread_create(&prg->mstrthrd, NULL, everwatcher, prg))
	{
		printf("Master thread failed to be knitted.\n");
		return (1);
	}
	return (0);
}

void	worldender(t_prg *prg)
{
	int	i;

	i = 0;
	free(prg->phls);
	free(prg->forks);
	while (i < prg->nop)
		pthread_mutex_destroy(&prg->forks[i++]);
}

int	main(int argc, char **argv)
{
	t_prg	prg;

	if (inputhandler(argc, argv, &prg))
		return (1);
	prg.starttime = mstime();
	if (utensilgenesis(&prg))
		return (1);
	if (philinit(&prg))
	{
		worldender(&prg);
		return (1);
	}
	pthread_join(prg.mstrthrd, NULL);
	worldender(&prg);
	return (0);
}
