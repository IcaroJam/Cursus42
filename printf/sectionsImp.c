/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sectionsImp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 16:26:50 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void static	deflager(t_flags *flags)
{
	flags->dash = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->minfw = 0;
	flags->hash = 0;
	flags->spc = 0;
	flags->plus = 0;
}

void static	flager(char **str, t_flags *flags)
{
	while (1)
	{
		if (**str == '-')
			flags->dash = 1;
		else if (**str == '0')
			flags->zero = 1;
		else if (**str == '.')
			flags->dot = 1;
		else if (**str >= '1' && **str <= '9')
			flags->minfw = ptf_atoi(str);
		else if (**str == '#')
			flags->hash = 1;
		else if (**str == ' ')
			flags->spc = 1;
		else if (**str == '+')
			flags->plus = 1;
		else
			break;
		str[0]++;
	}
}

int static	omniparser(char const **str, va_list list)
{
	t_flags	flags;

	deflager(&flags);
	
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
			if (omniparser(&str, list))
				return (-1);
	}
	va_end(list);
	ft_putstr(finalstr);
	return (ft_strlen(finalstr));
}
