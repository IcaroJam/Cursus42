/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagsAndConversions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 17:40:51 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/28 17:43:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int static	ptf_atoi(char const **str)
{
	int	ret;

	ret = 0;
	while (**str >= '0' && **str <= '9')
	{
		ret *= 10;
		ret += *(*str)++ - '0';
	}
	return (ret);
}

int static	converser(char const **str, t_flags *flags)
{
	if (**str == '%')
		flags->conv = **str;
	else if (**str == 'c')
		flags->conv = **str;
	else if (**str == 's')
		flags->conv = **str;
	else if (**str == 'd')
		flags->conv = **str;
	else if (**str == 'i')
		flags->conv = **str;
	else if (**str == 'u')
		flags->conv = **str;
	else if (**str == 'p')
		flags->conv = **str;
	else if (**str == 'x')
		flags->conv = **str;
	else if (**str == 'X')
		flags->conv = **str;
	else
		return (1);
	str[0]++;
	return (0);
}

void	deflager(t_flags *flags)
{
	flags->conv = 0;
	flags->dash = 0;
	flags->zero = 0;
	flags->dot = 0;
	flags->minfw = 0;
	flags->hash = 0;
	flags->spc = 0;
	flags->plus = 0;
}

int	flager(char const **str, t_flags *flags)
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
			break ;
		str[0]++;
	}
	return (converser(str, flags));
}
