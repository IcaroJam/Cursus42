/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digit_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:19:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/09 17:09:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	separator(char *ret, t_flags flags, int seplen)
{
	int		i;
	char	padding;

	i = 0;
	padding = ' ';
	if (flags.zero && !flags.dash && !flags.dot)
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

void static	getthatlength(t_digitlens *lens, t_flags flags, char *temp)
{
	lens->isneg = 0;
	lens->num = 0;
	lens->sign = 0;
	lens->prec = 0;
	lens->spaces = 0;
	if (!(flags.dot && !flags.pcsn && *temp == '0'))
	{
		if (*temp == '-')
		{
			lens->num = ptf_strlen(temp) - 1;
			lens->isneg = 1;
		}
		else
			lens->num = ptf_strlen(temp);
	}
	if (*temp == '-' || flags.plus || flags.spc)
		lens->sign = 1;
	if (flags.pcsn > lens->num)
		lens->prec = flags.pcsn - lens->num;
	if (flags.minfw > lens->sign + lens->prec + lens->num)
		lens->spaces = flags.minfw - lens->sign - lens->prec - lens->num;
	lens->total = lens->spaces + lens->sign + lens->prec + lens->num;
}

char	*ptf_digit(t_flags flags, va_list list)
{
	t_digitlens	lengths;
	char		*ret;
	char		*temp;
	int			i;

	temp = ptf_itoa(va_arg(list, int));
	if (!temp)
		return (NULL);
	getthatlength(&lengths, flags, temp);
	ret = ptf_zalloc(lengths.total);
	if (!ret)
		return (NULL);
	i = 0;
	if (flags.zero && flags.dot)
		flags.zero = 0;
	if (!flags.dash && !flags.zero)
		i += separator(ret, flags, lengths.spaces);
	i += signature(&ret[i], *temp, flags);
	if (flags.zero)
		i += separator(&ret[i], flags, lengths.spaces);
	while (flags.pcsn-- > lengths.num)
		ret[i++] = '0';
	if (*temp == '-')
		temp++;
	if (lengths.num)
		while (*temp)
			ret[i++] = *temp++;
	if (flags.dash)
		separator(&ret[i], flags, lengths.spaces);
	free (temp - lengths.num - lengths.isneg);
	return (ret);
}

// SEPARADOR // SIGNO/ESPACIO // RELLENO DE PCS // NUM // SEPARADOR
