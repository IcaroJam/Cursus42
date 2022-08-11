/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:02:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/10 19:34:21 by ntamayo-         ###   ########.fr       */
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
		if (!pthread_mutex_init(&prg->forks[i], NULL))
		{
			printf("Philosopher %d is unborn D:\n", i + 1);
			return (1);
		}
		prg->phls[i].id = i + 1;
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
		if (!pthread_create(&prg->phls[i].philo, NULL, , NULL))
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
	if (utensilgenesis(prg))
		return (1);
	prg->phls = malloc(sizeof(t_philosopher) * prg->nop);
	if (!prg->phls)
	{
		printf("Not enough room for those thicc philobois.\n");
		return (1);
	}
	if (philogenesis(prg))
		return (1);
	if (pthread_create(&prg->mstrthrd, NULL, , NULL))
	{
		printf("Master thread failed to be knitted.\n");
		return (1);
	}
	return (0);
}

void	worldender(t_prg *prg)
{
	free(prg->phls);
	free(prg->forks);
}

int	main(int argc, char **argv)
{
	t_prg	prg;

	if (inputhandler(argc, argv, &prg))
		return (1);
	if (philinit(&prg))
	{
		worldender(&prg);
		return (1);
	}
////////////////////////////////////////////////////////////////////////////////
	printf("nop: %d, ttd: %d, tte: %d, tts: %d, notepme: %d\n", prg.nop, prg.ttd, prg.tte, prg.tts, prg.notepme);
////////////////////////////////////////////////////////////////////////////////
	return (0);
}
