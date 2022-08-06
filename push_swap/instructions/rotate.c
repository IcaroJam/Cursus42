/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:12:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 19:24:22 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_rotate(t_stack *stack)
{
	t_num	temp;
	int		i;

	i = stack->top - 1;
	temp.num = stack->stk[i].num;
	temp.flg = stack->stk[i].flg;
	while (i > 0)
	{
		stack->stk[i].num = stack->stk[i - 1].num;
		stack->stk[i].flg = stack->stk[i - 1].flg;
		i--;
	}
	stack->stk[i].num = temp.num;
	stack->stk[i].flg = temp.flg;
}

void	ps_ra(t_stack *a)
{
	ps_rotate(a);
	write(1, "ra\n", 3);
}

void	ps_rb(t_stack *b)
{
	ps_rotate(b);
	write(1, "rb\n", 3);
}

void	ps_rr(t_stack *a, t_stack *b)
{
	ps_rotate(a);
	ps_rotate(b);
}
