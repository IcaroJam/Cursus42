/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/23 14:57:55 by ntamayo-         ###   ########.fr       */
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
			if (need_expansion(cts[0].cmndtable[i]))
			{
				tokenlen = get_tknlen(cts[0].cmndtable[i]);
				temp = ft_calloc(tokenlen + 1, sizeof(char));
				if (!temp)
					return (1);
				tokencpy(cts[0].cmndtable[i], tokenlen, temp);
				free(cts[0].cmndtable[i]);
				cts[0].cmndtable[i] = temp;
			}
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

static int	valupdate(char cmpval, char c, int *num)
{
	if (c == cmpval)
		*num = 1;
	return (1);
}

void	ioflager(t_parsing *cts, const char **tokenarr)
{
	int	cm;
	int	in;
	int	ou;

	cm = 0;
	in = 0;
	ou = 0;
	while (*tokenarr)
	{
		if (**tokenarr == '|')
		{
			cm++;
			in = 0;
			ou = 0;
		}
		else if (tokenarr[0][0] == '<')
			in += valupdate('<', tokenarr[0][1], &cts[cm].iflgs[in]);
		else if (tokenarr[0][0] == '>')
			ou += valupdate('>', tokenarr[0][1], &cts[cm].oflgs[ou]);
		tokenarr++;
	}
}

void	set_tablelast(t_parsing *cts, const int i)
{
	cts[i].cmndtable = NULL;
	cts[i].ins = NULL;
	cts[i].outs = NULL;
	cts[i].islast = 1;
}
