/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_II.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:13:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/30 15:06:33 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

char	*ft_addchr(char *str, char const c, int currlen)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ret = malloc(sizeof(char) * (currlen + 2));
	if (!ret)
		return (NULL);
	while (currlen)
	{
		*ret++ = str[i++];
		currlen--;
	}
	*ret++ = c;
	*ret = 0;
	free(str);
	return (ret - i - 1);
}

int	ptf_truelen(t_pbuff *buffer)
{
	int		nullnum;
	int		ret;

	nullnum = buffer->nulls;
	ret = 0;
	while (nullnum)
	{
		while (buffer->buff[ret])
			ret++;
		ret++;
		nullnum--;
	}
	ret += ft_strlen(&buffer->buff[ret]);
	return (ret);
}
