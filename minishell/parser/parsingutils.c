/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/20 13:11:58 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msparser.h"

int	expand_quotes(t_parsing *cts)
{
	int		i;
	int		tokenlen;
	char	*temp;

	while (!cts->islast)
	{
		i = 0;
		while (cts[0].cmndtable[i])
		{
			// Find tokens with expansible shit.
			if (need_expansion(cts[0].cmndtable[i]))
			{
			// Get the len of the tokens once expanded. (Wildcards should also
			// be considered in here).
			tokenlen = get_tknlen(cts[0].cmndtable[i]);
			// Allocate space for them.
			temp = ft_calloc(tokenlen, sizeof(char));
			if (!temp)
				return (1);
			tokencpy(cts[0].cmndtable[i], tokenlen, temp);
			free(cts[0].cmndtable[i]);
			cts[0].cmndtable[i] = temp;
			// Do the expansion.
			// Expand $ UNLESS it is inside single quotes.
			// A single $ will always print $.
			}
			i++;
		}
		cts++;
	}
	return (0);
}

int	stff_aid(char **chain, const char **tkns, int *i, int *qtty)
{
	int	len;

	if (!ft_strncmp(tkns[*i], "<<", 3))
	{
		chain[*qtty] = ft_strdup("HEREDOC");
		if (!chain[*qtty])
			return (1);
	}
	else
	{
		if (tkns[*i][0] == '<' || tkns[*i][0] == '>')
			(*i)++;
		len = ft_strlen(tkns[*i]) + 1;
		chain[*qtty] = ft_calloc(len, sizeof(char));
		if (!chain[*qtty])
			return (1);
		ft_strlcpy(chain[*qtty], tkns[*i], len);
	}
	(*qtty)++;
	return (0);
}

void	ioflager(t_parsing *cts, const char **tokenarr)
{
	int	cm;
	int	in;
	int	ou;

	cm = 0;
	in = 0;
	ou = 0;
	printf("SEG?\n");
	while (*tokenarr)
	{
		if (**tokenarr == '|')
			cm++;
		else if (tokenarr[0][0] == '<')
		{
			if (tokenarr[0][1] == '<')
				cts[cm].iflgs[in] = 1;
			in++;
		}
		else if (tokenarr[0][0] == '>')
		{
			if (tokenarr[0][1] == '>')
				cts[cm].oflgs[ou] = 1;
			ou++;
		}
		tokenarr++;
	}
	printf("SEG??\n");
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
		free(cts[i].iflgs);
		free(cts[i].oflgs);
		i++;
	}
	free(cts);
}
