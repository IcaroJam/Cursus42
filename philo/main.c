/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 14:02:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/10 18:54:02 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int static	utensilgenesis(t_prg *prg)
{
	prg->forks = malloc(sizeof(pthread_mutex_t) * prg->nop);
	if (!prg->forks)
		return (1);
	return (0);
}

int static	philinit(t_prg *prg)
{
	if (utensilgenesis(prg))
	{
		printf("Failed to allocate cupboard space for the forks.\n");
		return (1);
	}
	prg->phls = malloc(sizeof(t_philosopher) * prg->nop);
	if (!prg->phls)
	{
		printf("Not enough room for those thicc philobois.\n");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_prg	prg;

	if (inputhandler(argc, argv, &prg))
		return (1);
	if (philinit(&prg))
		return (1);
////////////////////////////////////////////////////////////////////////////////
	printf("nop: %d, ttd: %d, tte: %d, tts: %d, notepme: %d\n", prg.nop, prg.ttd, prg.tte, prg.tts, prg.notepme);
////////////////////////////////////////////////////////////////////////////////
	return (0);
}
