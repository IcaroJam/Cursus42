/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:29:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/28 17:54:09 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

int	argumentator(char const **str, va_list list)
{
	int		ret;
	t_flags	flags;

	ret = 0;
	str[0]++;
	deflager(&flags);
	if (flager(str, &flags))
		return (-1);
	
	return (ret);
}

int	ft_printf(char const *str, ...)
{
	int		ret;
	int		temp;
	va_list	list;

	ret = 0;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			temp = argumentator(&str, list);
			if (temp < 0)
				return (-1);
			else
				ret += temp;
		}
		else
		{
			ret++;
			write(1, str, 1);
		}
		str++;
	}
	va_end(list);
	return (ret);
}
