/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/14 17:23:29 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "msparser.h"

static int	get_varlen(const char *str, const char flag)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '$' && str[i] != flag && !ft_isspace(str[i]))
		i++;
	return (i);
}

static int	get_quotelen(const char *str, const char flag, int *i)
{
	int		qlen;
	int		temp;
	char	*var;

	qlen = 0;
	(*i)++;
	while (str[*i] && str[*i] != flag)
	{
		if (str[*i] == '$' && flag == '\"')
		{
			temp = get_varlen(&str[*i + 1], flag);
			var = ft_substr(&str[*i], 1, temp);
			*i += temp;
			temp = ft_strlen(getenv(var));
			free(var);
			if (temp > -1)
				qlen += temp;
		}
		else if (str[*i] != '$')
			qlen++;
		(*i)++;
	}
	return (qlen);
}

static int	get_tknlen(const char *str)
{
	int	tlen;
	int	i;

	i = 0;
	tlen = 0;
	while (str[i])
	{
		// Optimize this and add $ condition!!!
		if ((str[i] == '\'' || str[i] == '\"')
			&& handle_quotes(&str[i], str[i]))
			tlen += get_quotelen(str, str[i], &i);
		else
			tlen++;
		i++;
	}
	return (tlen);
}

/** static void	tokencpy(const char *line, int tknlen, char *cmdline)
  * {
  *     int		i;
  *     char	tmp;
  *
  *     i = 0;
  *     while (i < tknlen)
  *     {
  *         if ((*line == '\'' || *line == '\"') && handle_quotes(line, *line))
  *         {
  *             tmp = *line;
  *             line++;
  *             while (*line != tmp)
  *                 cmdline[i++] = *line++;
  *         }
  *         else
  *         {
  *             cmdline[i++] = *line++;
  *         }
  *     }
  * } */

static int	need_expansion(const char *str)
{
	int	temp;
	int	expandflag;

	expandflag = 0;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			temp = handle_quotes(str, *str);
			if (temp && *str == '\"')
				expandflag = 1;
			str += temp;
		}
		else if (*str == '$' && !ft_isspace(str[1]))
			expandflag = 1;
		str++;
	}
	return (expandflag);
}

int	expand_quotes(t_parsing *cts)
{
	int	i;
	int	tokenlen;

	//
	printf("TKNLEN: %d\n", get_tknlen(cts[0].cmndtable[1]));
	return (0);
	//
	while (!cts->islast)
	{
		i = 1;
		while (cts[0].cmndtable[i])
		{
			// Find tokens with expansible shit.
			if (!need_expansion(cts[0].cmndtable[i]))
				continue ;
			// Get the len of the tokens once expanded. (Wildcards should also
			// be considered in here).
			tokenlen = get_tknlen(cts[0].cmndtable[i]);
			// Allocate space for them.
			// Do the expansion.
			// Expand $ UNLESS it is inside single quotes.
			// A single $ will always print $.
			i++;
		}
		cts++;
	}
	return (0);
}

int	stff_aid(char **chain, const char **tkns, int *qtty)
{
	int	len;

	len = ft_strlen(*tkns) + 1;
	chain[*qtty] = ft_calloc(len, sizeof(char));
	if (!chain[*qtty])
		return (1);
	ft_strlcpy(chain[*qtty], *tkns, len);
	(*qtty)++;
	return (0);
}

void	set_tablelast(t_parsing *cts, const int i)
{
	cts[i].cmndtable = NULL;
	cts[i].ins = NULL;
	cts[i].outs = NULL;
	cts[i].islast = 1;
}

void	free_tables(t_parsing *cts)
{
	int	i;

	i = 0;
	if (!cts)
		return ;
	while (!cts[i].islast)
	{
		free_cmndline(cts[i].cmndtable);
		free_cmndline(cts[i].ins);
		free_cmndline(cts[i].outs);
		i++;
	}
	free(cts);
}
