/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/01 15:39:26 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	prepbuff(t_pbuff *buffer)
{
	buffer->buff = malloc(sizeof(char));
	if (!buffer->buff)
		return ;
	buffer->buff[0] = 0;
	buffer->nulls = 0;
	buffer->len = 0;
}

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
	else if (flags.conv == 's')
		ret = ptf_string(flags, list);
	/** else if (flags.conv == 'd')
	  *     ret =
	  * else if (flags.conv == 'i')
	  *     ret =
	  * else if (flags.conv == 'u')
	  *     ret =
	  * else if (flags.conv == 'p')
	  *     ret =
	  * else if (flags.conv == 'x' || conv == 'X')
	  *     ret = */
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
	if (!argumentstr)
		return (1);
	if (flags.conv == 'c' && !*argumentstr)
	{
		buffer->nulls++;
		buffer->buff = ft_addchr(buffer->buff, 0, buffer->len);
	}
	else
		buffer->buff = ptf_strjoin(buffer, argumentstr);
	free(argumentstr);
	argumentstr = NULL;
	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	t_pbuff	buffer;

	prepbuff(&buffer);
	va_start(list, str);
	while (*str)
	{
		buffer.buff = ft_concsection(&buffer, &str);
		buffer.len = ptf_truelen(&buffer);
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
	return (buffer.len);
}
/** 
  * #include <stdio.h>
  *
  * int	main(void)
  * {
  *     int	i;
  *
  *     i = ft_printf(" %c %c %c ", '2', '1', 0);
  *     printf("\nDevuelve: %d\n", i);
  *     i = printf(" %c %c %c ", '2', '1', 0);
  *     printf("\nDevuelve: %d", i);
  *     return (0);
  * } */
