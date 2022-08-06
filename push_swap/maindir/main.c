/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:19:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 18:51:53 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.stk = NULL;
	b.stk = NULL;
	if (!inputhandler(argc, argv))
	{
		stackinit(argc - 1, argv + 1, &a, &b);
		if (issorted(a))
		{
			freestacks(&a, &b);
			return (0);
		}
		solveit(&a, &b);
	}
	freestacks(&a, &b);
	return (0);
}
