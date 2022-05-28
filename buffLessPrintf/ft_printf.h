/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/28 17:44:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_flags
{
	char	conv;
	int		dash;
	int		zero;
	int		dot;
	int		minfw;
	int		hash;
	int		spc;
	int		plus;
}	t_flags;

int		ft_printf(char const *str, ...);
int		argumentator(char const **str);
void	deflager(t_flags *flags);
int	flager(char const **str, t_flags *flags);

#endif
