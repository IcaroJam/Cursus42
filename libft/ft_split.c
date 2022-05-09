/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:35:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/03 09:50:59 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_stringalloc(char const *str, char c, size_t *newoff)
{
	char	*ret;
	size_t	wlen;

	wlen = 0;
	while (str[wlen] && str[wlen] != c)
		wlen++;
	ret = (char *) malloc((wlen + 1) * sizeof(char));
	*newoff = wlen;
	if (!ret)
	{
		free(ret);
		return (NULL);
	}
	ft_strlcpy(ret, str, wlen + 1);
	return (ret);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	words;

	words = 0;
	while (*s)
	{
		if ((*s != c && *(s + 1) == c) || (*s != c && !*(s + 1)))
			words++;
		s++;
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	i;
	size_t	words;
	size_t	retindex;

	if (!s)
		return (0);
	words = ft_wordcount(s, c);
	ret = (char **) malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	i = 0;
	retindex = 0;
	while (words)
	{
		while (*s == c)
			s++;
		ret[retindex] = ft_stringalloc(s, c, &i);
		s = &s[i];
		words--;
		retindex++;
	}
	ret[retindex] = NULL;
	return (ret);
}
