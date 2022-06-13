/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/13 13:00:34 by ntamayo-         ###   ########.fr       */
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
	buffer->nflag = 0;
}

char static	*percent(t_flags flags)
{
	char	*ret;
	int		i;

	if (!flags.minfw)
		flags.minfw = 1;
	ret = ptf_zalloc(flags.minfw);
	if (!ret)
		return (NULL);
	i = 0;
	if (!flags.dash)
		while (flags.minfw-- > 1)
			ret[i++] = ' ';
	ret[i++] = '%';
	if (flags.dash)
		while (flags.minfw-- > 1)
			ret[i++] = ' ';
	return (ret);
}

char static	*argumentor(t_flags flags, va_list list, t_pbuff *buffer)
{
	char	*ret;

	if (flags.conv == '%')
		ret = percent(flags);
	else if (flags.conv == 'c')
		ret = ptf_chars(flags, list, buffer);
	else if (flags.conv == 's')
		ret = ptf_string(flags, list);
	else if (flags.conv == 'd')
		ret = ptf_digit(flags, list);
	else if (flags.conv == 'i')
		ret = ptf_digit(flags, list);
	else if (flags.conv == 'u')
		ret = ptf_unsigned(flags, list);
	else if (flags.conv == 'p')
		ret = ptf_pointer(flags, list);
	else if (flags.conv == 'x' || flags.conv == 'X')
		ret = ptf_hex(flags, list);
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
	argumentstr = argumentor(flags, list, buffer);
	if (!argumentstr)
		return (1);
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
		buffer.buff = ptf_concsection(&buffer, &str);
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
  *     i = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
  *     printf("\nDevuelve: %d\n", i);
  *     i = printf(" %-1c %-2c %-3c ", '0', 0, '1');
  *     printf("\nDevuelve: %d", i);
  *     //system("leaks a.out");
  *     return (0);
  * } */
