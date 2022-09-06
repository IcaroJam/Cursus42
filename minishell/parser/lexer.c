/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:57:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/06 13:07:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	count_isspace(const char *line)
{
	int	ret;

	ret = 0;
	while (ft_isspace(line[ret]))
		ret++;
	return (ret);
}

static int	handle_quotes(const char *line, const char flag)
{
	int	ret;

	ret = 0;
	while (line[ret] != flag && line[ret])
		ret++;
	if (!line[ret])
		return (1);
	return (ret);
}

static int	process_word(const char *line)
{
	int		ret;

	ret = 0;
	while (line[ret] && !ft_isspace(line[ret]))
	{
		if (line[ret] == '\'' || line[ret] == '"')
			ret += handle_quotes(line, *line);
		else
			ret++;
	}
	return (ret);
}

static int	count_words(const char *line)
{
	int	ret;

	ret = 0;
	while (*line)
	{
		line += count_isspace(line);
		line += process_word(line);
		ret++;
	}
	return (ret);
}

char	**tokenize_line(char *line)
{
	char	**ret;

	if (!*line)
		return (NULL);
	return (ret);
}
