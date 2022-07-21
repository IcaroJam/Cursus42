/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:12:25 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/21 10:12:34 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void static	ps_push(t_stack *p_from, t_stack *p_to)
{
	if (!p_from->top)
		return ;
	p_to->stk[p_to->top++] = p_from->stk[--p_from->top];
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
