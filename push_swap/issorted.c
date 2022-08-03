/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   issorted.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 12:19:38 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/03 13:14:24 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	getsmolish(t_stack *stack)
{
	int	i;
	int	temp;
	int	ret;
	int	smol;

	smol = getsmol(stack);
	i = stack->top - 1;
	ret = i;
	temp = 2147483647;
	while (!stack->stk[i].flg && i > -1)
	{
		if (stack->stk[i].num < temp
			&& stack->stk[i].num > stack->stk[smol].num)
		{
			ret = i;
			temp = stack->stk[i].num;
		}
		i--;
	}
	return (ret);
}

int	getsmol(t_stack *stack)
{
	int	i;
	int	temp;
	int	ret;

	i = stack->top - 1;
	ret = i;
	temp = 2147483647;
	while (!stack->stk[i].flg && i > -1)
	{
		if (stack->stk[i].num < temp)
		{
			ret = i;
			temp = stack->stk[i].num;
		}
		i--;
	}
	return (ret);
}

int	ispartsorted(t_stack stack)
{
	int	i;

	i = stack.top - 2;
	if (i < 0)
		return (1);
	while (!stack.stk[i].flg && i > -1)
	{
		if (stack.stk[i].num < stack.stk[i + 1].num)
			return (0);
		i--;
	}
	return (1);
}

int	issorted(t_stack stack)
{
	int	i;

	i = 0;
	stack.top--;
	while (i < stack.top)
	{
		if (stack.stk[i].num < stack.stk[i + 1].num)
			return (0);
		i++;
	}
	return (1);
}
