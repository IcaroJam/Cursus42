/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 15:58:15 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/03 09:53:13 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
