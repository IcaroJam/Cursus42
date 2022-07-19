/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:19:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/19 14:41:17 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	inputhandler(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	argv++;
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
		write(1, "a", 1);
	// DO STUFF
	}
	return (0);
}
