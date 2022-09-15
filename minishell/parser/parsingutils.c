/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/15 15:37:04 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msparser.h"

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

int	expand_quotes(t_parsing *cts)
{
	int	i;
	int	tokenlen;

	while (!cts->islast)
	{
		i = 1;
		while (cts[0].cmndtable[i])
		{
			// Find tokens with expansible shit.
			if (need_expansion(cts[0].cmndtable[i]))
			{
			// Get the len of the tokens once expanded. (Wildcards should also
			// be considered in here).
			tokenlen = get_tknlen(cts[0].cmndtable[i]);
			// Allocate space for them.
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
