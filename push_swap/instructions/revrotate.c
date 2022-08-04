/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   revrotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:54:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/04 13:34:01 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void static	ps_revrotate(t_stack *stack)
{
	t_num	temp;
	int		lim;
	int		i;

	i = 0;
	lim = stack->top - 1;
	temp.num = stack->stk[0].num;
	temp.flg = stack->stk[0].flg;
	while (i < lim)
	{
		stack->stk[i].num = stack->stk[i + 1].num;
		stack->stk[i].flg = stack->stk[i + 1].flg;
		i++;
	}
	stack->stk[i].flg = temp.flg;
	stack->stk[i].num = temp.num;
}

void	ps_rra(t_stack *a)
{
	ps_revrotate(a);
	write(1, "rra\n", 4);
}

void	ps_rrb(t_stack *b)
{
	ps_revrotate(b);
	write(1, "rrb\n", 4);
}

void	ps_rrr(t_stack *a, t_stack *b)
{
	ps_revrotate(a);
	ps_revrotate(b);
	write(1, "rrr\n", 4);
}
