/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:35:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/11 09:32:34 by ntamayo-         ###   ########.fr       */
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

static void	*ft_destroyer(char **arr, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
		free(arr[i++]);
	free(arr);
	return (NULL);
}

static char	**ft_strstringer(char **ret, size_t words, char c, char const *s)
{
	size_t	i;
	size_t	retindex;
	size_t	wsplit;

	wsplit = 0;
	retindex = 0;
	while (wsplit < words)
	{
		while (*s == c)
			s++;
		ret[retindex++] = ft_stringalloc(s, c, &i);
		s += i;
		wsplit++;
		if (!ret[retindex - 1])
		{
			ft_destroyer(ret, wsplit);
			break ;
		}
	}
	if (wsplit == words)
		ret[retindex] = NULL;
	return (ret);
}

char	**ft_split(char const *s, char c)
{
	char	**ret;
	size_t	words;

	if (!s)
		return (0);
	words = ft_wordcount(s, c);
	ret = (char **) malloc((words + 1) * sizeof(char *));
	if (!ret)
		return (NULL);
	ret = ft_strstringer(ret, words, c, s);
	return (ret);
}
