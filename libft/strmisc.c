/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strmisc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 16:50:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/22 21:28:13 by ntamayo-         ###   ########.fr       */
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
