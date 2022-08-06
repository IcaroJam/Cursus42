/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:12:25 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 19:20:02 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_push(t_stack *p_from, t_stack *p_to)
{
	if (!p_from->top)
		return ;
	p_to->stk[p_to->top++].num = p_from->stk[--p_from->top].num;
}

void	ps_pa(t_stack *a, t_stack *b)
{
	ps_push(b, a);
	write(1, "pa\n", 3);
}

void	ps_pb(t_stack *a, t_stack *b)
{
	ps_push(a, b);
	write(1, "pb\n", 3);
}
