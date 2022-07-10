/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipesplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:35:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/10 18:16:53 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_stringalloc(char const *str, char c, size_t *newoff)
{
	char	*ret;
	char	flag;
	size_t	wlen;

	wlen = 0;
	if (str[wlen] == 34 || str[wlen] == 39)
	{
		flag = str[wlen];
		str++;
		while (str[wlen] && str[wlen] != flag)
			wlen++;
		if (str[wlen] != flag)
			return (NULL);
	}
	else
		while (str[wlen] && str[wlen] != c)
			wlen++;
	ret = malloc(sizeof(char) * (wlen + 1));
	if (!ret)
		return (NULL);
	*newoff = wlen;
	ft_strlcpy(ret, str, wlen + 1);
	return (ret);
}

static size_t	ft_wordcount(char const *s, char c)
{
	size_t	words;
	char	flag;

	flag = 0;
	words = 0;
	while (*s)
	{
		if (*s == 34 || *s == 39)
		{
			if (flag)
				flag = 0;
			else
				flag = *s;
		}
		if (flag)
		{
			s++;
			continue ;
		}
		else if ((*s != c && *(s + 1) == c) || (*s != c && !*(s + 1)))
			words++;
		s++;
	}
	return (words);
}

static void	ft_destroyer(char **arr, size_t words)
{
	size_t	i;

	i = 0;
	while (i < words)
		free(arr[i++]);
	free(arr);
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
		ret[retindex] = ft_stringalloc(s, c, &i);
		s += i;
		wsplit++;
		if (!ret[retindex])
		{
			ft_destroyer(ret, wsplit);
			return (NULL);
		}
		retindex++;
	}
	if (wsplit == words)
		ret[retindex] = NULL;
	return (ret);
}

char	**pipesplit(char const *s, char c)
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
