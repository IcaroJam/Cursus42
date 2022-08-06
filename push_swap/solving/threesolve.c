/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threesolve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 11:28:20 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 12:21:49 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void static	emptystksolve(t_stack *a)
{
	int	smolindex;

	smolindex = getsmol(a);
	if (smolindex == 2)
	{
		ps_sa(a);
		ps_ra(a);
	}
	else if (smolindex == 1)
	{
		if (a->stk[0].num < a->stk[2].num)
			ps_ra(a);
		else
			ps_sa(a);
	}
	else
	{
		if (a->stk[2].num < a->stk[1].num)
			ps_rra(a);
		else
		{
			ps_sa(a);
			ps_rra(a);
		}
	}
}

void static	backflip(t_stack *a, t_stack *b)
{
	ps_pb(a, b);
	ps_sa(a);
	ps_pa(a, b);
}

void static	filledstksolve(t_stack *a, t_stack *b)
{
	int	smolindex;

	smolindex = getsmol(a);
	if (smolindex == a->top - 1)
		backflip(a, b);
	else if (smolindex == a->top - 2)
	{
		if (a->stk[a->top - 3].num < a->stk[a->top - 1].num)
		{
			ps_sa(a);
			backflip(a, b);
		}
		else
			ps_sa(a);
	}
	else
	{
		if (a->stk[a->top - 2].num < a->stk[a->top - 1].num)
			ps_sa(a);
		backflip(a, b);
		ps_sa(a);
	}
}

void	threesolve(t_stack *a, t_stack *b)
{
	if (ispartsorted(*a))
		return ;
	if (a->top == 3)
		emptystksolve(a);
	else if (a->top < 3)
		ps_sa(a);
	else
		filledstksolve(a, b);
}
