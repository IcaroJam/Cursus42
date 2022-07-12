/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipesplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 18:35:40 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/12 14:34:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./mandatory/pipex.h"

static char	*ft_stringalloc(char const **str, char c, size_t *newoff)
{
	char	*ret;
	char	flag;
	size_t	i;

	i = 0;
	if (**str == 34 || **str == 39)
	{
		str[0]++;
		flag = *(*str - 1);
		while (str[0][i] && str[0][i] != flag)
			i++;
	}
	else
		while (str[0][i] && str[0][i] != c)
			i++;
	ret = malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (NULL);
	ft_strlcpy(ret, *str, i + 1);
	*newoff = i;
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
			if (*s == 39)
				s++;
			if (*s == 34)
				s++;
			flag = *s - 1;
			while (*s != flag && *s)
				s++;
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
		ret[retindex] = ft_stringalloc(&s, c, &i);
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
