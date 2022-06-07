/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:19:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/07 10:58:34 by ntamayo-         ###   ########.fr       */
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

char	*ptf_digit(t_flags flags, va_list list)
{
	char	*ret;
	char	*temp;
	int		inplen;
	int		hassign;
	int		i;

	temp = ptf_itoa(va_arg(list, int));
	if (!temp)
		return (NULL);
	inplen = ptf_strlen(temp);
	hassign = 0;
	if (flags.spc || flags.plus)
		hassign = 1;
	if (flags.minfw < (unsigned int) inplen + hassign)
		flags.minfw = inplen;
	ret = ptf_zalloc(flags.minfw + hassign);
	if (!ret)
		return (NULL);
	i = 0;
	if (!flags.dash)
		i = separator(ret, flags, flags.minfw - inplen - hassign);
	i += signature(&ret[i], *temp, flags);
	while (flags.pcsn-- > (unsigned int) inplen)
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
