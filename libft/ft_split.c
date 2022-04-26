/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:35:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/26 19:33:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static char	*ft_stringalloc(char const *str, char c, size_t *newoff)
{
	char	*ret;
	size_t	i;

	i = 0;
	while (!str[i] && str[i] != c)
		i++;
	ret = (char *) malloc((i + 1) * sizeof(char));
	if (!ret)
		return (0);
	*newoff = i + 1;
	ft_strlcpy(ret, str, i + 1);
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	divnum;

	if (!s)
		return (0);
	i = 0;
	divnum = 0;
	while (s[i])
	{
		if (s[i] == c)
			divnum++;
		i++;
	}
	ret = (char **) malloc((divnum + 2) * sizeof(char *));
	if (!ret)
		return (0);
	i = 0;
	divnum = 0;
	while (divnum + 1)
	{
		*ret = ft_stringalloc(&s[i], c, &i);
		divnum--;
		(*ret)++;
	}
	*ret = NULL;
	return (ret);
}
