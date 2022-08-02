/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:19:56 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/02 15:20:57 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void static	stackinit(int n, char **argv, t_stack *a, t_stack *b)
{
	int	i;

	a->stk = malloc(sizeof(t_num) * n);
	b->stk = malloc(sizeof(t_num) * n);
	if (!a->stk || !b->stk)
		errmsg("Stack allocation failed.");
	a->size = n;
	b->size = n;
	a->top = 0;
	b->top = 0;
	i = n - 1;
	while (a->top < n)
	{
		a->stk[a->top].flg = 0;
		b->stk[a->top].flg = 0;
		a->stk[a->top++].num = ft_atoi(argv[i--]);
	}
}

void static	checkdups(char **argv)
{
	int	head;
	int	search;

	head = 1;
	while (argv[head])
	{
		search = 0;
		while (search < head)
		{
			if (!ft_strncmp(argv[head], argv[search], ft_strlen(argv[head])))
				errmsg("Duplicates present.");
			search++;
		}
		head++;
	}
}

int static	inputhandler(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		return (1);
	argv++;
	checkdups(argv);
	while (*argv)
	{
		i = 0;
		if (argv[0][i] == '-')
			i++;
		while (argv[0][i])
		{
			if (!ft_isdigit(argv[0][i++]))
				errmsg("Input contains invalid characters.");
		}
		argv++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	if (!inputhandler(argc, argv))
	{
		stackinit(argc - 1, argv + 1, &a, &b);
		fivesolve(&a, &b);
	}
	return (0);
}
