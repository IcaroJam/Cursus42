/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sectionsImp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 15:54:08 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ft_omniparser(char const **str, va_list list)
{
	
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
			if (ft_omniparser(&str, list))
				return (-1);
	}
	va_end(list);
	ft_putstr(finalstr);
	return (ft_strlen(finalstr));
}
