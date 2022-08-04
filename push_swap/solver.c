/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:11:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/04 18:51:06 by ntamayo-         ###   ########.fr       */
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
	int	rotated;

	rotated = 0;
	i = numsinpartition(a);
	if (i < 6)
		return (1);
	median = medianget(*a);
	while (i && !a->stk[a->top - 1].flg)
	{
		if (a->top < 6)
			return (1);
		if (a->stk[a->top - 1].num > median)
		{
			ps_ra(a);
			rotated++;
		}
		else
			ps_pb(a, b);
		i--;
	}
	while (i++ < rotated)
		ps_rra(a);
	b->stk[b->top - 1].flg = 1;
	return (0);
}

int static	brrase(t_stack *a, t_stack *b)
{
	int	median;
	int	pushedto;
	int	i[2];

	b->stk[b->top - 1].flg = 0;
	i[0] = numsinpartition(b);
	i[1] = 0;
	if (!i[0])
		return (6);
	if (i[0] < 6)
	{
		while (i[0]--)
			ps_pa(a, b);
		return (1);
	}
	pushedto = 0;
	median = medianget(*b);
	while (i[0] && !b->stk[b->top - 1].flg)
	{
		if (b->stk[b->top - 1].num < median)
		{
			ps_rb(b);
			i[1]++;
		}
		else
		{
			ps_pa(a, b);
			pushedto++;
		}
		i[0]--;
	}
	while (i[0]++ < i[1])
		ps_rrb(b);
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
			fivesolve(a, b);
			while (brrase(a, b) < 6)
			{
				fivesolve(a, b);
				if (issorted(*a))
					a->stk[a->top - 1].flg = 1;
			}
			b->stk[b->top - 1].flg = 1;
		}
	}
}
