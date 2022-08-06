/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:50:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 17:21:13 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int static	checkcommand(t_stack *a, t_stack *b, char *cmnd)
{
	if (ft_strncmp("sa", cmnd, 3))
		ps_sa(a);
	else if (ft_strncmp("sb", cmnd, 3))
		ps_sb(b);
	else if (ft_strncmp("ss", cmnd, 3))
		ps_ss(a, b);
	else if (ft_strncmp("pa", cmnd, 3))
		ps_pa(a, b);
	else if (ft_strncmp("pb", cmnd, 3))
		ps_pb(a, b);
	else if (ft_strncmp("ra", cmnd, 3))
		ps_ra(a);
	else if (ft_strncmp("rb", cmnd, 3))
		ps_rb(b);
	else if (ft_strncmp("rr", cmnd, 3))
		ps_rr(a, b);
	else if (ft_strncmp("rra", cmnd, 4))
		ps_rra(a);
	else if (ft_strncmp("rrb", cmnd, 4))
		ps_rrb(b);
	else if (ft_strncmp("rrr", cmnd, 4))
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
		stackinit(argc - 1, argv, &a, &b);
		command_gen(&a, &b);
		if (issorted(a) && !b.top)
			ft_putendl_fd("OK", 1);
		else
			ft_putendl_fd("KO", 1);
	}
	freestacks(&a, &b);
	return (0);
}
