/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_III.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:11:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/31 18:38:57 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char	*ptf_chars(t_flags flags, va_list list)
{
	char	*ret;
	int		c;
	int		i;

	if (!flags.minfw)
		flags.minfw = 1;
	ret = malloc(sizeof(char) * (1 + flags.minfw));
	if (!ret)
		return (NULL);
	c = va_arg(list, int);
//	ret[0] = c;
//	ret[1] = 0;
	i = 0;
	if (flags.dash)
	{
		ret[i++] = c;
		while (i < flags.minfw)
			ret[i++] = ' ';
	}
	else
	{
		flags.minfw--;
		while (i < flags.minfw)
			ret[i++] = ' ';
		ret[i++] = c;
	}
	ret[i] = 0;
	return (ret);
}

/** char	*ptf_string(t_flags flags, va_list list)
  * {
  *     char	*ret;
  *     char	*str;
  *
  *     str = va_arg(list, char *);
  * } */

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
