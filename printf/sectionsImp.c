/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sectionsImp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 15:19:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 13:23:45 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

/** char static	*ft_addchr(char *str, char const c, int currlen)
  * {
  *     char	*ret;
  *
  *     if (!str)
  *         return (NULL);
  *     ret = malloc(sizeof(char) * (currlen + 1));
  *     if (!ret)
  *         return (NULL);
  *     while (*str)
  *         *ret++ = *str++;
  *     *ret++ = c;
  *     *ret = 0;
  *     free(str - currlen);
  *     return (ret - currlen - 1);
  * }
  *
  * int static	ft_omniparser(char const *str, va_list list)
  * {
  *     int		errflag;
  *     int		currlen;
  *     char	*finalstr;
  *
  *     finalstr = malloc(sizeof(char));
  *     if (!finalstr)
  *         return (-1);
  *     *finalstr = 0;
  *     errflag = 1;
  *     currlen = 0;
  *     while (*str && errflag)
  *     {
  *         if (*str == '%')
  *         {
  *         }
  *         else
  *         {
  *             finalstr = ft_addchr(finalstr, *str, currlen);
  *             if (!finalstr)
  *                 return (-1);
  *             currlen++;
  *         }
  *         str++;
  *     }
  *     ft_putstr(finalstr);
  *     return (currlen);
  * } */

int static	ptf_sectlen(char *str)
{
	int	ret;

	ret = 0;
	while (str[ret] && str[ret] != '%')
		ret++;
	return (ret);
}

char static	*ft_concsection(char *finalstr, char **str)
{
	int		fslen;
	int		slen;
	char	*ret;

	if (!finalstr || !*str)
		return (NULL);
	fslen = ft_strlen(finalstr);
	slen = ptf_sectlen(*str);
	ret = malloc(sizeof(char) * (fslen + slen + 1));
	if (!ret)
		return (NULL);
	while (*finalstr)
		*ret++ = *finalstr++;
	while (**str && **str != '%')
		*ret++ = *(*str)++;
	*ret = 0;
	free(finalstr - fslen);
	return (ret - fslen - slen);
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
		if ()
	}
	va_end(list);
	ft_putstr(finalstr);
	return (ft_strlen(finalstr));
}
