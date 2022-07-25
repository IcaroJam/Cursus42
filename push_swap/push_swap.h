/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 12:15:03 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/25 13:41:44 by ntamayo-         ###   ########.fr       */
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

// Instructions.
void	ps_pa(t_stack *a, t_stack *b);
void	ps_pb(t_stack *a, t_stack *b);
void	ps_sa(t_stack *a);
void	ps_sb(t_stack *b);
void	ps_ss(t_stack *a, t_stack *b);
void	ps_ra(t_stack *a);
void	ps_rb(t_stack *b);
void	ps_rr(t_stack *a, t_stack *b);

#endif
