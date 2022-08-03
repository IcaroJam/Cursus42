/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errxit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:14:37 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/03 13:08:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	errmsg(char *msg)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(msg, 2);
	exit(1);
}

void	freestacks(t_stack *a, t_stack *b)
{
	free(a->stk);
	free(b->stk);
}
