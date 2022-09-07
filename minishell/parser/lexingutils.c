/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexingutils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 13:12:17 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/07 12:41:55 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

int	count_isspace(const char *line)
{
	int	ret;

	ret = 0;
	while (ft_isspace(line[ret]))
		ret++;
	return (ret);
}

int	handle_quotes(const char *line, const char flag)
{
	int	ret;

	ret = 1;
	while (line[ret] != flag && line[ret])
		ret++;
	if (!line[ret])
		return (0);
	return (ret);
}

int	handle_redir(const char *line)
{
	if (*line == '<' || *line == '>')
		if (line[1] == line[0])
			return (2);
	return (1);
}

static int	process_word(const char *line)
{
	int	ret;

	ret = 0;
	while (line[ret] && !ft_isspace(line[ret]) && line[ret] != '<'
			&& line[ret] != '>' && line[ret] != '|')
	{
		if (line[ret] == '\'' || line[ret] == '\"')
			ret += handle_quotes(&line[ret], line[ret]);
		ret++;
	}
	return (ret);
}

int	count_words(const char *line)
{
	int	numow;

	numow = 0;
	while (*line)
	{
		line += count_isspace(line);
		if (*line == '<' || *line == '>' || *line == '|')
			line += handle_redir(line);
		else
			line += process_word(line);
		numow++;
	}
	return (numow);
}