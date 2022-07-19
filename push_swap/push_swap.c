/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:19:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/19 15:00:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	checkdups(char **argv)
{
	int	head;
	int	search;

	head = 1;
	while (argv[head])
	{
		search = 0;
		while (search < head)
		{
			if (!ft_strncmp(argv[head], argv[search], ft_strlen(argv[head])))
				errmsg("Duplicates present.");
			search++;
		}
		head++;
	}
}

int static	inputhandler(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	argv++;
	checkdups(argv);
	while (*argv)
	{
		i = 0;
		if (argv[0][i] == '-')
			i++;
		while (argv[0][i])
		{
			if (!ft_isdigit(argv[0][i++]))
				errmsg("Input contains invalid characters.");
		}
		argv++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (!inputhandler(argc, argv))
	{
		return (1);
	}
	return (0);
}
