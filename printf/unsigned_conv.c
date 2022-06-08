/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:19:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/08 18:54:56 by ntamayo-         ###   ########.fr       */
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

void static	getthatlength(t_digitlens *lens, t_flags flags, char *temp)
{
	lens->num = 0;
	lens->prec = 0;
	lens->spaces = 0;
	if (!(flags.dot && !flags.pcsn && *temp == '0'))
		lens->num = ptf_strlen(temp);
	if (flags.pcsn > lens->num)
		lens->prec = flags.pcsn - lens->num;
	if (flags.minfw > lens->prec + lens->num)
		lens->spaces = flags.minfw - lens->prec - lens->num;
	lens->total = lens->spaces + lens->prec + lens->num;
}

char	*ptf_unsigned(t_flags flags, va_list list)
{
	t_digitlens	lengths;
	char		*ret;
	char		*temp;
	int			i;

	temp = ptf_utoa(va_arg(list, unsigned int));
	if (!temp)
		return (NULL);
	getthatlength(&lengths, flags, temp);
	ret = ptf_zalloc(lengths.total);
	if (!ret)
		return (NULL);
	i = 0;
	if (flags.zero && flags.dot)
		flags.zero = 0;
	i += separator(&ret[i], flags, lengths.spaces);
	while (flags.pcsn-- > lengths.num)
		ret[i++] = '0';
	if (lengths.num)
		while (*temp)
			ret[i++] = *temp++;
	if (flags.dash)
		separator(&ret[i], flags, lengths.spaces);
	free (temp - lengths.num);
	return (ret);
}

// SEPARADOR // SIGNO/ESPACIO // RELLENO DE PCS // NUM // SEPARADOR
