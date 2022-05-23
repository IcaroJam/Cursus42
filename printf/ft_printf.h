/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 10:33:00 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>

typedef struct s_flags
{
	int	dash;
	int	zero;
	int	dot;
	int	minfw;
	int	hash;
	int	spc;
	int	plus;
}	t_flags;

int	ft_printf(char const *str, ...);

#endif
