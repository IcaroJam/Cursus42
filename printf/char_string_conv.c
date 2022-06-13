/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_string_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:11:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/13 13:01:39 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	chrstrlens(t_flags flags, t_digitlens *lens, char *str)
{
	lens->spaces = 0;
	lens->prec = 0;
	if (flags.conv == 'c')
		lens->num = 1;
	else
	{
		lens->num = ptf_strlen(str);
		if (flags.dot && lens->num > flags.pcsn)
			lens->num = flags.pcsn;
	}
	if (flags.minfw > lens->num)
		lens->spaces = flags.minfw - lens->num;
	lens->total = lens->spaces + lens->num;
}

void static	nullidentify(t_pbuff *buffer, char c)
{
	buffer->nflag = 0;
	if (!c)
		buffer->nflag = 1;
}

char	*ptf_chars(t_flags flags, va_list list, t_pbuff *buffer)
{
	char		c;
	int			i;
	char		*ret;
	t_digitlens	lens;

	c = va_arg(list, int);
	nullidentify(buffer, c);
	chrstrlens(flags, &lens, &c);
	ret = ptf_zalloc(lens.total);
	if (!ret)
		return (NULL);
	i = 0;
	if (!flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
	ret[i++] = c;
	if (flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
	return (ret);
}

char	*ptf_string(t_flags flags, va_list list)
{
	char		*ret;
	char		*str;
	int			i;
	t_digitlens	lens;

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";
	chrstrlens(flags, &lens, str);
	ret = ptf_zalloc(lens.total);
	if (!ret)
		return (NULL);
	i = 0;
	if (!flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
	while (lens.num--)
		ret[i++] = *str++;
	if (flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
	return (ret);
}

void	ptf_putstr(t_pbuff *buffer)
{
	buffer->len = ptf_truelen(buffer);
	write(1, buffer->buff, buffer->len);
	free(buffer->buff);
}
