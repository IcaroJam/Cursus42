/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:19:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/07 15:04:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	separator(char *ret, t_flags flags, int seplen)
{
	int		i;
	char	padding;

	i = 0;
	padding = ' ';
	if (flags.zero && !flags.dash)
		padding = '0';
	while (seplen-- > 0)
		ret[i++] = padding;
	return (i);
}

int static	signature(char *ret, char c, t_flags flags)
{
	if (flags.plus && c != '-')
	{
		*ret = '+';
		return (1);
	}
	if (flags.spc && c != '-')
	{
		*ret = ' ';
		return (1);
	}
	if (c == '-')
	{
		*ret = '-';
		return (1);
	}
	return (0);
}

unsigned int static	undashedlen(char const *str, int inplen)
{
	if (*str == '-')
		return (inplen - 1);
	return (inplen);
}

unsigned int static	alloclen(t_flags flags, char *temp)
{
	unsigned int	spaces;
	unsigned int	sign;
	unsigned int	precision;
	unsigned int	num;

	sign = 0;
	if (*temp == '-' || flags.plus || flags.spc)
		sign = 1;
	if (*temp == '-')
		num = ptf_strlen(temp) - 1;
	else
		num = ptf_strlen(temp);
	precision = 0;
	if (flags.pcsn > num)
		precision = flags.pcsn - num;
	spaces = 0;
	if (flags.minfw > sign + precision + num)
		spaces = flags.minfw - sign - precision - num;
	return (spaces + sign + precision + num);
}

char	*ptf_digit(t_flags flags, va_list list)
{
	char	*ret;
	char	*temp;
	int		inplen;
	int		hassign;
	int		i;

	hassign = 0;
	if (flags.plus || flags.spc)
		hassign = 1;
	temp = ptf_itoa(va_arg(list, int));
	if (!temp)
		return (NULL);
	inplen = ptf_strlen(temp);
	ret = ptf_zalloc(alloclen(flags, temp));
	if (!ret)
		return (NULL);
	i = 0;
	if (!flags.dash && !flags.zero)
		i = separator(ret, flags, flags.minfw - inplen - hassign);
	i += signature(&ret[i], *temp, flags);
	if (flags.zero)
		i += separator(&ret[i], flags, flags.minfw - inplen - hassign);
	while (flags.pcsn-- > undashedlen(temp, inplen))
		ret[i++] = '0';
	if (*temp == '-')
		temp++;
	while (*temp)
		ret[i++] = *temp++;
	if (flags.dash)
		separator(&ret[i], flags, flags.minfw - inplen - hassign);
	free (temp - inplen);
	return (ret);
}

// SEPARADOR // SIGNO/ESPACIO // RELLENO DE PCS // NUM // SEPARADOR
