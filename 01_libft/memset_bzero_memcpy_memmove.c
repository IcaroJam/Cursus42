/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset_bzero_memcpy_memmove.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:48:48 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/19 15:08:41 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	newc;

	i = 0;
	newc = (unsigned char)c;
	while (i < len)
		((unsigned char *)b)[i++] = newc;
	return (b);
}
/*
#include <string.h>

int	main(void)
{
	char hey[] = "abcdefghi";

	printf("%s", hey);
	memset(hey, 57, 3);
	printf("%s", hey);
	ft_memset(hey, 55, 3);
	printf("%s", hey);
	return (0);
}*/
