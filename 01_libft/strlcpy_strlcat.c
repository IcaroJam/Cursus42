/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy_strlcat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 19:51:59 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/20 20:06:05 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
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

//size_t	ft_strlcat(char *restrict dst, const char *restrict src, size_t dstsize);

int	main(void)
{
	char a[] = "12345";
	strlcpy("abcde\0", a, 3);
	printf("%s\n", a);
}
