/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_bzero_memcpy_memmove.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:48:48 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/22 10:33:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*newb;

	newb = b;
	while (len--)
		*newb++ = c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	char	*temps;

	temps = s;
	while (n--)
		*temps++ = 0;
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
		while (len--)
			d[len] = s[len];
	return ((unsigned char *)dst);
}
/*
#include <strings.h>

int	main(void)
{
	char hey[] = "abcdefghi";
	char hou[] = "123456789";

	printf("%s\n", hey);
	printf("%s\n", ft_memmove(hou + 2, hou, 3));
	printf("%s\n", hey);
	ft_memcpy(hey, hou, 3);
	printf("%s\n", hey);
	return (0);
}*/
