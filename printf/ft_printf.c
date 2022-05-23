/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 11:59:13 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char static	*ft_addchr(char *str, char const c, int currlen)
{
	char	*ret;

	if (!str)
		return (NULL);
	ret = malloc(sizeof(char) * (currlen + 1));
	if (!ret)
		return (NULL);
	while (*str)
		*ret++ = *str++;
	*ret++ = c;
	*ret = 0;
	free(str - currlen);
	return (ret - currlen - 1);
}

int static	ft_omniparser(char const *str, va_list list)
{
	int		errflag;
	int		currlen;
	char	*finalstr;

	finalstr = malloc(sizeof(char));
	if (!finalstr)
		return (-1);
	*finalstr = 0;
	errflag = 1;
	currlen = 0;
	while (*str && errflag)
	{
		if (*str == '%')
		{
		}
		else
		{
			finalstr = ft_addchr(finalstr, *str, currlen);
			if (!finalstr)
				return (-1);
			currlen++;
		}
		str++;
	}
	ft_putstr(finalstr);
	return (currlen);
}

int	ft_printf(char const *str, ...)
{
	va_list	list;
	int		printdchrs;
	char	*finalstr;

	if (!str || !*str)
		return (-1);
	va_start(list, str);
	printdchrs = ft_omniparser(str, list);
	va_end(list);
	return (printdchrs);
}
