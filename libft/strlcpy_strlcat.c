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
//#include <stdio.h>
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
/*#include <string.h>
int	main(void)
{
	char *str = "the cake is a lie !\0I'm hidden lol\r\n";
//	char buff1[0xF00] = "there is no stars in the sky";
	char buff2[0xF00] = "there is no stars in the sky";
	size_t max = ft_strlen("the cake is a lie !\0I'm hidden lol\r\n") + 4;
//	char a[] = "12345\0.a.a.a.a.";
//	char b[] = "abcde.-.-.-";
	ft_strlcat(buff2, str, max);
	printf("%s\n", buff2);
}*/
