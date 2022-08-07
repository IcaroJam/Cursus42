/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:50:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 19:30:53 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int static	checkcommand(t_stack *a, t_stack *b, char *cmnd)
{
	if (!ft_strncmp("sa\n", cmnd, 4))
		ps_swap(a);
	else if (!ft_strncmp("sb\n", cmnd, 4))
		ps_swap(b);
	else if (!ft_strncmp("ss\n", cmnd, 4))
		ps_ss(a, b);
	else if (!ft_strncmp("pa\n", cmnd, 4))
		ps_push(b, a);
	else if (!ft_strncmp("pb\n", cmnd, 4))
		ps_push(a, b);
	else if (!ft_strncmp("ra\n", cmnd, 4))
		ps_rotate(a);
	else if (!ft_strncmp("rb\n", cmnd, 4))
		ps_rotate(b);
	else if (!ft_strncmp("rr\n", cmnd, 4))
		ps_rr(a, b);
	else if (!ft_strncmp("rra\n", cmnd, 5))
		ps_revrotate(a);
	else if (!ft_strncmp("rrb\n", cmnd, 5))
		ps_revrotate(b);
	else if (!ft_strncmp("rrr\n", cmnd, 5))
		ps_rrr(a, b);
	else
		return (1);
	return (0);
}

void static	command_gen(t_stack *a, t_stack *b)
{
	char	*cmnd;

	cmnd = get_next_line(0);
	while (cmnd)
	{
		if (checkcommand(a, b, cmnd))
		{
			free(cmnd);
			errmsg("Invalid command.");
		}
		free(cmnd);
		cmnd = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	a.stk = NULL;
	b.stk = NULL;
	if (!inputhandler(argc, argv))
	{
		stackinit(argc - 1, argv + 1, &a, &b);
		command_gen(&a, &b);
		if (issorted(a) && !b.top)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	freestacks(&a, &b);
	return (0);
}
