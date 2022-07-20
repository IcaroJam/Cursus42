/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:12:25 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/20 18:28:01 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ps_push(t_stack *p_from, t_stack *p_to)
{
	if (!p_from->top)
		return ;
	p_to->stk[p_to->top++] = p_from->stk[--p_from->top];
}
