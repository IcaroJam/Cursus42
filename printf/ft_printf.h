/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 15:55:45 by ntamayo-         ###   ########.fr       */
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

int		ft_printf(char const *str, ...);
int		ptf_sectlen(char const *str);
int		ft_strlen(char *str);
char	*ft_concsection(char *finalstr, char const **str);

#endif
