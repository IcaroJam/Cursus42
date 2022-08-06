/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   NEWsolver.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 11:11:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 10:52:21 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int static	a_split(t_stack *a, t_stack *b)
{
	int	i;
	int	median;
	int	numsfliped;

	i = partlen(a);
	if (i < 6)
		return (-1);
	median = medianget(*a);
	numsfliped = 0;
	while (i && !a->stk[a->top - 1].flg)
	{
		if (a->stk[a->top - 1].num > median)
		{
			ps_ra(a);
			numsfliped++;
		}
		else
			ps_pb(a, b);
		i--;
	}
	b->stk[b->top - 1].flg = 1;
	return (numsfliped);
}

void static	rev(t_stack *stack, int qtty, int flag)
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

void static	a_begin(t_stack *a, t_stack *b)
{
	while (a->top > 5)
		a_split(a, b);
	fivesolve(a, b);
	a->stk[a->top - 1].flg = 1;
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
		while (b_split(a, b) < 6)
		{
			fivesolve(a, b);
			if (issorted(*a))
				a->stk[a->top - 1].flg = 1;
		}
		b->stk[b->top - 1].flg = 1;
		while (partlen(a) > 5)
			rev(a, a_split(a, b), 1);
		fivesolve(a, b);
	}
}
