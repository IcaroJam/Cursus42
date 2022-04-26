/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 15:35:34 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/26 16:19:50 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	slen;

	slen = ft_strlen(s);
	if (slen <= start)
	{
		ret = (char *) malloc(sizeof(char));
		*ret = 0;
		return (ret);
	}
	if (slen - start < len)
		len = slen - start;
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, &s[start], len + 1);
	return (ret);
}
