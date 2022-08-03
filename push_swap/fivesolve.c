/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivesolve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:57:17 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/03 16:09:35 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	get_to_top(t_stack *a, int i, int useRev)
{
	if (useRev)
		while (i-- > -1)
			ps_rra(a);
	else
		while (i++ < a->top - 1)
			ps_ra(a);
}

void static	emptystksolve(t_stack *a, t_stack *b)
{
	int	smolindex;
	int	safeval;

	safeval = a->top;
	while (a->top > 3)
	{
		smolindex = getsmol(a);
		if (smolindex >= 2)
			get_to_top(a, smolindex, 0);
		else
			get_to_top(a, smolindex, 1);
		if (!ispartsorted(*a))
			ps_pb(a, b);
		else
			break ;
	}
	threesolve(a, b);
	while (a->top < safeval)
		ps_pa(a, b);
}

void static	movethem(t_stack *a, t_stack *b, t_num *tiny)
{
	tiny[0].num = a->stk[getsmol(a)].num;
	tiny[1].num = a->stk[getsmolish(a)].num;
	tiny[0].flg = 0;
	tiny[1].flg = 0;
	tiny[2].num = 0;
	if (tiny[0].num == tiny[1].num)
		return ;
	while (!tiny[0].flg || !tiny[1].flg)
	{
		if (a->stk[a->top - 1].num == tiny[0].num
			|| a->stk[a->top - 1].num == tiny[1].num)
		{
			if (a->stk[a->top - 1].num == tiny[0].num)
				tiny[0].flg = 1;
			else
				tiny[1].flg = 1;
			ps_pb(a, b);
		}
		else
		{
			ps_ra(a);
			tiny[2].num++;
		}
	}
}

void static	filledstksolve(t_stack *a, t_stack *b)
{
	t_num	tiny[3];

	movethem(a, b, &tiny[0]);
	while (tiny[2].num--)
		ps_rra(a);
	threesolve(a, b);
	ps_pa(a, b);
	ps_pa(a, b);
	if (a->stk[a->top - 1].num > a->stk[a->top - 2].num)
		ps_sa(a);
}

void	fivesolve(t_stack *a, t_stack *b)
{
	if (ispartsorted(*a))
		return ;
	if (a->top <= 5)
		emptystksolve(a, b);
	else
		filledstksolve(a, b);
}
