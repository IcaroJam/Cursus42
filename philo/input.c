/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 15:47:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/10 17:37:25 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int static	digitcheck(char *str)
{
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (1);
		str++;
	}
	return (0);
}

int static	overflowcheck(char **argv)
{
	while (*(++argv))
		if (ft_ioverflw(*argv))
			return (1);
	return (0);
}

int	second_layer(int argc, char **argv, t_prg *prg)
{
	prg->nop = ft_atoi(argv[1]);
	if (prg->nop < 2)
	{
		printf("Less than 2 philosophers sat at the table.\n");
		printf("Loneliness? Nothingness? Or reality-breaking amounts?\n");
		return (1);
	}
	prg->ttd = ft_atoi(argv[2]);
	prg->tte = ft_atoi(argv[3]);
	prg->tts = ft_atoi(argv[4]);
	if (argc == 6)
		prg->notepme = ft_atoi(argv[5]);
	return (0);
}

int	inputhandler(int argc, char **argv, t_prg *prg)
{
	int	i;

	i = 1;
	if (argc > 6 || argc < 5)
	{
		printf("Incorrect number of arguments.\n");
		return (1);
	}
	while (i < argc)
	{
		if (digitcheck(argv[i++]))
		{
			printf("Input contains invalid characters.\n");
			return (1);
		}
	}
	if (overflowcheck(argv))
	{
		printf("Input contains an overflowing value.\n");
		return (1);
	}
	if (second_layer(argc, argv, prg))
		return (1);
	return (0);
}
