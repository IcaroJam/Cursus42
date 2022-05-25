/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sectionsImp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/25 15:42:44 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"



int static	omniparser(char const **str, va_list list)
{
	t_flags	flags;

	deflager(&flags);
	str[0]++;
	if (flager(str, &flags))
		return (1);

	return (0);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	char	*finalstr;

	finalstr = malloc(sizeof(char));
	if (!finalstr || !str)
		return (-1);
	*finalstr = 0;
	va_start(list, str);
	while (*str)
	{
		finalstr = ft_concsection(finalstr, &str);
		if (!finalstr)
			return (-1);
		if (*str == '%')
		{
			if (omniparser(&str, list))
			{
				free(finalstr);
				return (-1);
			}
		}
	}
	va_end(list);
	ft_putstr(finalstr);
	return (ft_strlen(finalstr));
}
