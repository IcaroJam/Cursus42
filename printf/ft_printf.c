/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/26 15:50:21 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

char static	*argumentor(t_flags flags, va_list list)
{
	char	*ret;

	if (flags.conv == '%')
	{
		ret = malloc(sizeof(char) * 2);
		ret[0] = '%';
		ret[1] = 0;
	}
	else if (flags.conv == 'c')
		ret = ptf_chars(flags, list);
	/** else if (flags.conv == 's')
	  *     ret =
	  * else if (flags.conv == 'd')
	  *     ret =
	  * else if (flags.conv == 'i')
	  *     ret =
	  * else if (flags.conv == 'u')
	  *     ret =
	  * else if (flags.conv == 'p')
	  *     ret =
	  * else if (flags.conv == 'x' || conv == 'X')
	  *     ret =  */
	else
		return (NULL);
	return (ret);
}

int static	omniparser(char const **str, va_list list, t_pbuff *buffer)
{
	t_flags	flags;
	char	*argumentstr;

	deflager(&flags);
	str[0]++;
	if (flager(str, &flags))
		return (1);
	argumentstr = argumentor(flags, list);
	buffer->buff = ptf_strjoin(buffer->buff, argumentstr);
	free(argumentstr);
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	t_pbuff	buffer;

	buffer.buff = malloc(sizeof(char));
	if (!buffer.buff || !str)
		return (-1);
	*(buffer.buff) = 0;
	va_start(list, str);
	while (*str)
	{
		buffer.buff = ft_concsection(buffer.buff, &str);
		if (!buffer.buff)
			return (-1);
		if (*str == '%')
		{
			if (omniparser(&str, list, &buffer))
			{
				free(buffer.buff);
				return (-1);
			}
		}
	}
	va_end(list);
	ptf_putstr(&buffer);

	buffer.len = 0;

	return (buffer.len);
}

#include <stdio.h>

int	main(void)
{
	ft_printf(" %c %c %c ", '0', 0, '1');
	printf("\n %c %c %c ", '0', 0, '1');
	return (0);
}