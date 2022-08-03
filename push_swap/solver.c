/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:11:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/03 13:59:27 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	numsinpartition(t_stack *a)
{
	int	i;

	i = a->top - 1;
	while (!a->stk[i].flg && i > -1)
		i--;
	return (a->top - 1 - i);
}

int static	arrase(t_stack *a, t_stack *b)
{
	int	median;
	int	i;

	i = numsinpartition(a) - 1;
	if (i < 5)
	{
		fivesolve(a, b);
		return (1);
	}
	median = medianget(*a);
	while (i > -1 && !a->stk[a->top - 1].flg)
	{
		if (a->stk[a->top - 1].num > median)
			ps_ra(a);
		else
			ps_pb(a, b);
		i--;
	}
	b->stk[b->top - 1].flg = 1;
	return (0);
}

int static	brrase(t_stack *a, t_stack *b)
{
	int	median;
	int	pushedto;
	int	i;

	b->stk[b->top - 1].flg = 0;
	i = numsinpartition(b) - 1;
	if (i < 0)
		return (6);
	pushedto = 0;
	median = medianget(*b);
	while (i > -1 && !b->stk[b->top - 1].flg)
	{
		if (b->stk[b->top - 1].num <= median)
			ps_rb(b);
		else
		{
			ps_pa(a, b);
			pushedto++;
		}
		i--;
	}
	return (pushedto);
}

void	solveit(t_stack *a, t_stack *b)
{
	if (a->top < 6)
		fivesolve(a, b);
	while (!issorted(*a) || b->top)
	{
		if (arrase(a, b))
		{
			while (brrase(a, b) < 6)
				fivesolve(a, b);
			a->stk[a->top - 1].flg = 1;
		}
	}
}
