/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:11:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/20 18:21:27 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_swap(t_stack *stack)
{
	int	temp;

	if (stack->top <= 1)
		return ;
	temp = stack->stk[stack->top - 1];
	stack->stk[stack->top - 1] = stack->stk[stack->top - 2];
	stack->stk[stack->top - 2] = temp;
}

void	ps_ss(t_stack *a, t_stack *b)
{
	ps_swap(a);
	ps_swap(b);
}
