/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:57:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/09 12:18:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "msparser.h"

static int	get_quotelen(t_lexutil *lxu)
{
	int	qlen;

	qlen = handle_quotes(&lxu->line[lxu->lnoff], lxu->line[lxu->lnoff]);
	if (!qlen)
		return (1);
	lxu->lnoff += qlen;
	return (qlen - 1);
}

static int	get_tknlen(t_lexutil *lxu)
{
	int	tlen;

	tlen = 0;
	if (isredir(lxu->line[lxu->lnoff]))
	{
		lxu->lnoff = handle_redir(lxu->line);
		return (lxu->lnoff);
	}
	while (lxu->line[lxu->lnoff] && !ft_isspace(lxu->line[lxu->lnoff])
		&& !isredir(lxu->line[lxu->lnoff]))
	{
		if (lxu->line[lxu->lnoff] == '\'' || lxu->line[lxu->lnoff] == '\"')
			tlen += get_quotelen(lxu);
		else
			tlen++;
		lxu->lnoff++;
	}
	return (tlen);
}

static void	tokencpy(const char *line, int tknlen, char *cmdline)
{
	int		i;
	char	tmp;

	i = 0;
	while (i < tknlen)
	{
		if ((*line == '\'' || *line == '\"') && handle_quotes(line, *line))
		{
			tmp = *line;
			line++;
			while (*line != tmp)
				cmdline[i++] = *line++;
		}
		else
		{
			cmdline[i++] = *line++;
		}
	}
}

static int	tokenstr(char **cmdline, t_lexutil *lxu, int numow)
{
	int		tknlen;
	int		i;

	i = 0;
	while (i < numow)
	{
		lxu->lnoff = 0;
		lxu->line += count_isspace(&lxu->line[lxu->lnoff]);
		tknlen = get_tknlen(lxu);
		cmdline[i] = ft_calloc(tknlen + 1, sizeof(char));
		if (!cmdline[i])
		{
			free_cmndline(cmdline);
			return (1);
		}
		tokencpy(lxu->line, tknlen, cmdline[i]);
		lxu->line += lxu->lnoff;
		i++;
	}
	return (0);
}

char	**tokenize_line(char *line)
{
	t_lexutil	lxu;
	char		**ret;
	int			numow;

	numow = count_words(line);
	ret = ft_calloc(numow + 1, sizeof(char *));
	if (!ret)
		return (NULL);
	lxu.line = line;
	if (tokenstr(ret, &lxu, numow))
		return (NULL);
	if (check_redirerr((const char **)ret))
	{
		free_cmndline(ret);
		return (NULL);
	}
	return (ret);
}
