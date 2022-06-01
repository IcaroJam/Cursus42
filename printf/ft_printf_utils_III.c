/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_III.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:11:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/01 15:34:24 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ptf_chars(t_flags flags, va_list list)
{
	char				*ret;
	unsigned int		i;

	if (!flags.minfw)
		flags.minfw = 1;
	ret = ptf_zalloc(flags.minfw);
	if (!ret)
		return (NULL);
	i = 0;
	if (flags.dash)
		ret[i++] = va_arg(list, int);
	else
		flags.minfw--;
	while (i < flags.minfw)
		ret[i++] = ' ';
	if (!flags.dash)
		ret[i++] = va_arg(list, int);
	return (ret);
}

char	*ptf_string(t_flags flags, va_list list)
{
	char	*ret;
	char	*str;
	int		inplen;
	int		i;

	str = va_arg(list, char *);
	inplen = ptf_strlen(str);
	if (!flags.minfw)
		flags.minfw = inplen;
	ret = ptf_zalloc(flags.minfw);
	if (!ret)
		return (NULL);
	if (flags.dot)
		inplen = flags.pcsn;
	i = 0;
	flags.minfw -= inplen;
	if (flags.dash)
		while (inplen--)
			ret[i++] = *str++;
	while (flags.minfw--)
		ret[i++] = ' ';
	if (!flags.dash)
		while (inplen--)
			ret[i++] = *str++;
	return (ret);
}

void	ptf_putstr(t_pbuff *buffer)
{
	int	i;
	int	templen;

	i = 0;
	buffer->len = ptf_truelen(buffer);
	templen = buffer->len;
	while (templen)
	{
		write(1, &buffer->buff[i], 1);
		i++;
		templen--;
	}
	free(buffer->buff);
}
