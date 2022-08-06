/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:11:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 11:25:24 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rev(t_stack *stack, int qtty, int flag)
{
	int	i;

	i = 0;
	if (flag)
		while (i++ < qtty)
			ps_rra(stack);
	else
		while (i++ < qtty)
			ps_rrb(stack);
}

void	solveit(t_stack *a, t_stack *b)
{
	if (a->top < 6)
	{
		fivesolve(a, b);
		return ;
	}
	a_begin(a, b);
	while (!issorted(*a) || b->top)
	{
		b_divide(a, b);
		b->stk[b->top - 1].flg = 1;
		while (partlen(a) > 5)
			rev(a, a_split(a, b), 1);
		fivesolve(a, b);
	}
}
