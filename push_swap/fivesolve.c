/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fivesolve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 14:57:17 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/02 15:51:12 by ntamayo-         ###   ########.fr       */
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
	while (a->top < 5)
		ps_pa(a, b);
}

void static	filledstksolve()
{
	return ;
}

void	fivesolve(t_stack *a, t_stack *b)
{
	if (ispartsorted(*a))
		return ;
	if (a->top == 5)
		emptystksolve(a, b);
	else
		filledstksolve();
}
