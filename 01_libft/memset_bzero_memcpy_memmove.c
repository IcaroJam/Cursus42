/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_bzero_memcpy_memmove.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:48:48 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/20 16:10:55 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

// Old, inefficient Ver
/*
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	newc;

	i = 0;
	newc = (unsigned char)c;
	while (i < len)
		((unsigned char *)b)[i++] = newc;
	return (b);
}*/

// Casting the int into an unsigned char isn't necessary 4 sum reason
void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*newb;

	newb = b;
	while (len-- > 0)
		*newb++ = c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	char *temps;

	temps = s;
	while (n-- > 0)
		*temps++ = 0;
}

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;

	d = dst;
	s = src;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}

// memmove implementation with dynamic size buffer string
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	temp[len];

	ft_memcpy(temp, src, len);
	ft_memcpy(dst, temp, len);
	return ((unsigned char *)dst);
}
/*
#include <strings.h>

int	main(void)
{
	char hey[] = "abcdefghi";
	char hou[] = "123456789";

	printf("%s\n", hey);
	printf("%s %s\n", ft_memmove(hou + 2, hou, 3), hey);
	printf("%s\n", hey);
	ft_memcpy(hey, hou, 3);
	printf("%s\n", hey);
	return (0);
}*/
