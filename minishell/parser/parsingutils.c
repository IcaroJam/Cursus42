/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/13 18:51:44 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msparser.h"

/** static int	get_quotelen(t_lexutil *lxu)
  * {
  *     int	qlen;
  *
  *     qlen = handle_quotes(&lxu->line[lxu->lnoff], lxu->line[lxu->lnoff]);
  *     if (!qlen)
  *         return (1);
  *     lxu->lnoff += qlen;
  *     return (qlen - 1);
  * }
  *
  * static int	get_tknlen(t_lexutil *lxu)
  * {
  *     int	tlen;
  *
  *     tlen = 0;
  *     if (isredir(lxu->line[lxu->lnoff]))
  *     {
  *         lxu->lnoff = handle_redir(lxu->line);
  *         return (lxu->lnoff);
  *     }
  *     while (lxu->line[lxu->lnoff] && !ft_isspace(lxu->line[lxu->lnoff])
  *         && !isredir(lxu->line[lxu->lnoff]))
  *     {
  *         if (lxu->line[lxu->lnoff] == '\'' || lxu->line[lxu->lnoff] == '\"')
  *             tlen += get_quotelen(lxu);
  *         else
  *             tlen++;
  *         lxu->lnoff++;
  *     }
  *     return (tlen);
  * } */

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
