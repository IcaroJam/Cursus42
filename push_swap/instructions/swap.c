/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:11:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/21 10:16:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void static	ps_swap(t_stack *stack)
{
	int	temp;

	if (stack->top <= 1)
		return ;
	temp = stack->stk[stack->top - 1];
	stack->stk[stack->top - 1] = stack->stk[stack->top - 2];
	stack->stk[stack->top - 2] = temp;
}

void	ps_sa(t_stack *a)
{
	ps_swap(a);
	write(1, "sa\n", 3);
}

void	ps_sb(t_stack *b)
{
	ps_swap(b);
	write(1, "sb\n", 3);
}

void	ps_ss(t_stack *a, t_stack *b)
{
	ps_swap(a);
	ps_swap(b);
	write(1, "ss\n", 3);
}
