/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:51:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/21 20:12:05 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
//#include <string.h>
#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	if (dstsize)
	{
		while (dstsize - 1 && src)
		{
			*dst++ = *src++;
			dstsize--;
		}
		*dst = 0;
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	dstlen;
	int		nulcond;

	nulcond = 0;
	if (dstsize && (dstlen <= dstsize))
		nulcond = 1;
	dstlen = ft_strlen(dst);
	dst += dstlen;
	while (dstsize - dstlen - 1 && src)
	{
		*dst++ = *src++;
		dstsize--;
	}
	if (nulcond)
		*dst = 0;
	return (ft_strlen(dst) + ft_strlen(src));
}
/*
int	main(void)
{
	char a[] = "12345";
	char b[] = "abcde";
	ft_strlcpy(b, a, 3);
	printf("%s\n", b);
}*/
