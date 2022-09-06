/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:57:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/06 17:19:49 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "msparser.h"

static int	count_words(const char *line)
{
	int	numow;

	numow = 0;
	while (*line)
	{
		line += count_isspace(line);
		line += process_word(line);
		numow++;
	}
	return (numow);
}

static int	get_quotelen(const char **line)
{
	int	qlen;
	int	openquote;

	qlen = 0;
	openquote = handle_quotes(*line, **line);
	if (openquote == 1)
	{
		while (**line && !ft_isspace(**line) && **line != '<' && **line != '>')
		{
			line[0]++;
			qlen++;
		}
		return (qlen);
	}
	*line += openquote;
	return (openquote - 2);
}

static int	get_tknlen(const char *line)
{
	int	tlen;

	tlen = 0;
	if (line[0] == '<')
	{
		if (line [1] == '<')
			return (8);
		return (4);
	}
	if (line[0] == '>')
	{
		if (line[1] == '>')
			return (10);
		return (5);
	}
	while (*line && !ft_isspace(*line) && *line != '<' && *line != '>')
	{
		if (*line == '\'' || *line == '"')
			tlen += get_quotelen(&line);
		else if (*line != '<' && *line != '>')
			tlen++;
	}
	return (0);
}

static char	**tokenstr(const char *line, int numow)
{
	char	**ret;
	int		tknlen;
	int		i;

	i = 0;
	while (i++ < numow)
	{
		line += count_isspace(line);
		tknlen = get_tknlen(line);
	}
	return (ret);
}

char	**tokenize_line(char *line)
{
	char	**ret;
	int		numow;

	if (!*line)
		return (NULL);
	numow = count_words(line);
	ret = ft_calloc(numow, sizeof(char *));
	if (!ret)
		return (NULL);
	ret = tokenstr(line, numow);
	// Parsing errors like <<< here !!!
	return (ret);
}
