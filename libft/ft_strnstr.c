/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:00:44 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/03 09:53:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		i = 0;
		while (len && needle[i] && haystack [i] && haystack[i] == needle[i])
		{
			if (!needle[i + 1])
				return ((char *)haystack);
			i++;
			len--;
		}
		haystack++;
		len--;
	}
	return (0);
}
