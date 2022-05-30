/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:20:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/30 14:22:37 by ntamayo-         ###   ########.fr       */
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

typedef struct s_pbuff
{
	char	*buff;
	int		nulls;
	int		len;
}	t_pbuff;

int		ft_printf(char const *str, ...);
void	deflager(t_flags *flags);
int		flager(char const **str, t_flags *flags);
int		ptf_sectlen(char const *str);
int		ft_strlen(char const *str);
void	ptf_putstr(t_pbuff *buffer);
int		ptf_truelen(t_pbuff *buffer);
char	*ft_concsection(t_pbuff *buffer, char const **str);
char	*ptf_strjoin(t_pbuff *buffer, char *str);
char	*ft_addchr(char *str, char const c, int currlen);
int		ptf_atoi(char const **str);
char	*ptf_chars(t_flags flags, va_list list);

#endif
