/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:51:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/22 17:16:10 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (dstsize)
	{
		while (dstsize - 1 && *src)
		{
			*dst++ = *src++;
			dstsize--;
		}
		*dst = 0;
	}
	return (srclen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dstlen;
	size_t	srclen;
	int		nulcond;

	nulcond = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (dstlen >= dstsize)
		return (dstsize + srclen);
	if (dstsize)
		nulcond = 1;
	dst += dstlen;
	while ((dstsize - dstlen - 1) && *src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (nulcond)
		*dst = 0;
	return (dstlen + srclen);
}
