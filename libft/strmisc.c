/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmisc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:50:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/23 20:09:32 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s || !c)
	{
		if (*s == c)
			return ((char *)s);
		s++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	const char	*revs;

	revs = s + ft_strlen(s);
	while (revs >= s)
	{
		if (*revs == c)
			return ((char *)revs);
		revs--;
	}
	return (0);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n > 0)
	{
		if (*s1 == 0 && *s1 == *s2)
			return (0);
		if (*s1 != *s2)
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
		s1++;
		s2++;
		n--;
	}
	return (0);
}
