/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_ops.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:16:53 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 12:22:01 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	a_split(t_stack *a, t_stack *b)
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

void	a_begin(t_stack *a, t_stack *b)
{
	while (a->top > 5)
		a_split(a, b);
	fivesolve(a, b);
	a->stk[a->top - 1].flg = 1;
}
