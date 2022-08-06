/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:19:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 15:59:20 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	stackinit(int n, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	a->stk = malloc(sizeof(t_num) * n);
	b->stk = malloc(sizeof(t_num) * n);
	if (!a->stk || !b->stk)
		errmsg("Stack allocation failed.");
	a->size = n;
	b->size = n;
	a->top = 0;
	b->top = 0;
	i = n - 1;
	while (a->top < n)
	{
		a->stk[a->top].flg = 0;
		b->stk[a->top].flg = 0;
		a->stk[a->top++].num = ft_atoi(argv[i--]);
	}
}

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
