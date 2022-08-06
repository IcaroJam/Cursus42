/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:15:03 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/06 12:39:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_num
{
	int	num;
	int	flg;
}	t_num;

typedef struct s_stack
{
	t_num	*stk;
	int		top;
	int		size;
}	t_stack;

// Error and exit functions.
void	errmsg(char *msg);
void	freestacks(t_stack *a, t_stack *b);

// Instructions.
void	ps_pa(t_stack *a, t_stack *b);
void	ps_pb(t_stack *a, t_stack *b);
void	ps_sa(t_stack *a);
void	ps_sb(t_stack *b);
void	ps_ss(t_stack *a, t_stack *b);
void	ps_ra(t_stack *a);
void	ps_rb(t_stack *b);
void	ps_rr(t_stack *a, t_stack *b);
void	ps_rra(t_stack *a);
void	ps_rrb(t_stack *b);
void	ps_rrr(t_stack *a, t_stack *b);

// Median stuff.
int		medianget(t_stack stack);
int		partlen(t_stack *stack);

// Solving.
void	threesolve(t_stack *a, t_stack *b);
void	fivesolve(t_stack *a, t_stack *b);
void	solveit(t_stack *a, t_stack *b);

// A stack thangs
int		a_split(t_stack *a, t_stack *b);
void	a_begin(t_stack *a, t_stack *b);

// B stack thangs
void	b_divide(t_stack *a, t_stack *b);

// Misc.
int		inputhandler(int argc, char **argv);
int		ispartsorted(t_stack stack);
int		issorted(t_stack stack);
int		getsmol(t_stack *stack);
int		getsmolish(t_stack *stack);
void	rev(t_stack *stack, int qtty, int flag);

#endif
