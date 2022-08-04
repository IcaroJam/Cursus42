/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 14:45:57 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/04 18:24:16 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	copypartition(int *ordstk, t_stack stack, int temp)
{
	while (temp < stack.top)
		*ordstk++ = stack.stk[temp++].num;
}

void static	orderstack(int *ordstk, int upperlim)
{
	int	j;
	int	temp;

	while (upperlim)
	{
		j = 0;
		while (j < upperlim - 1)
		{
			if (ordstk[j] < ordstk[j + 1])
			{
				temp = ordstk[j + 1];
				ordstk[j + 1] = ordstk[j];
				ordstk[j] = temp;
			}
			j++;
		}
		upperlim--;
	}
}

int	medianget(t_stack stack)
{
	int	temp;
	int	*ordstk;
	int	ret;

	temp = stack.top - 1;
	while (!stack.stk[temp].flg && temp)
		temp--;
	temp++;
	ordstk = malloc(sizeof(int) * (stack.top - temp));
	if (!ordstk)
		errmsg("Couldn't allocate the memory needed to look for the median.");
	copypartition(ordstk, stack, temp);
	orderstack(ordstk, stack.top - temp);
	ret = ordstk[(stack.top - temp) / 2];
	free (ordstk);
	return (ret);
}

int	partlen(t_stack *stack)
{
	int	i;

	i = stack->top - 1;
	while (!stack->stk[i].flg && i > -1)
		i--;
	return (stack->top - 1 - i);
}
