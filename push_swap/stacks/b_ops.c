/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:20:39 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 12:22:07 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int static	b_check(t_stack *a, t_stack *b, int i)
{
	if (i < 6)
	{
		while (i--)
			ps_pa(a, b);
		return (1);
	}
	return (0);
}

int static	b_deal(t_stack *a, t_stack *b, int len)
{
	int	pushedto;
	int	median;
	int	numsfliped;

	pushedto = 0;
	numsfliped = 0;
	median = medianget(*b);
	while (len && !b->stk[b->top - 1].flg)
	{
		if (b->stk[b->top - 1].num < median)
		{
			ps_rb(b);
			numsfliped++;
		}
		else
		{
			ps_pa(a, b);
			pushedto++;
		}
		len--;
	}
	if (partlen(b) < b->top)
		rev(b, numsfliped, 0);
	return (pushedto);
}

int static	b_split(t_stack *a, t_stack *b)
{
	int	pushedto;
	int	i;

	b->stk[b->top - 1].flg = 0;
	i = partlen(b);
	if (!i)
		return (6);
	if (b_check(a, b, i))
		return (1);
	pushedto = b_deal(a, b, i);
	return (pushedto);
}

void	b_divide(t_stack *a, t_stack *b)
{
	while (b_split(a, b) < 6)
	{
		fivesolve(a, b);
		if (issorted(*a))
			a->stk[a->top - 1].flg = 1;
	}
}
