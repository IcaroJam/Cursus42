/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_III.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:11:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/30 20:00:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char	*ptf_chars(t_flags flags, va_list list)
{
	char	*ret;
	int		c;

	flags.zero = 0;
	ret = malloc(sizeof(char) * 2);
	if (!ret)
		return (NULL);
	c = va_arg(list, int);
	ret[0] = c;
	ret[1] = 0;
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
