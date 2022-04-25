/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memmisc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:26:01 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/23 20:34:13 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*temp;
	unsigned char		val;

	temp = s;
	val = c;
	while (n--)
	{
		if (*temp == val)
			return ((unsigned char *)temp);
		temp++;
	}
	return (0);
}


