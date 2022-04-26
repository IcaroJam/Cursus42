/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 16:53:27 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/26 18:31:22 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	roff;
	size_t	loff;
	char	*ret;

	if (!set || !s1)
		return (0);
	loff = 0;
	while (s1[loff] && ft_strchr(set, s1[loff]))
		loff++;
	roff = ft_strlen(s1);
	while (roff && ft_strchr(set, s1[roff - 1]))
		roff--;
	ret = ft_substr(s1, loff, roff - loff);
	return (ret);
}
