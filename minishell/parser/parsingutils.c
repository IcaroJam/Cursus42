/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingutils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/13 18:04:56 by ntamayo-         ###   ########.fr       */
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

int	stuff_outs(t_parsing *cts, const char **tkns, int *qtty)
{
	int	len;

	len = ft_strlen(*tkns);
	cts->outs[*qtty] = ft_calloc(len, sizeof(char));
	if (!cts->outs[*qtty])
		return (1);
	ft_strlcpy(cts->outs[*qtty], *tkns, len);
	(*qtty)++;
	return (0);
}

int	stuff_ins(t_parsing *cts, const char **tkns, int *qtty)
{
	int	len;

	len = ft_strlen(*tkns);
	cts->ins[*qtty] = ft_calloc(len, sizeof(char));
	if (!cts->ins[*qtty])
		return (1);
	ft_strlcpy(cts->ins[*qtty], *tkns, len);
	(*qtty)++;
	return (0);
}

int	stuff_cmnd(t_parsing *cts, const char **tkns, int *qtty)
{
	int	len;

	len = ft_strlen(*tkns);
	cts->cmndtable[*qtty] = ft_calloc(len, sizeof(char));
	if (!cts->cmndtable[*qtty])
		return (1);
	ft_strlcpy(cts->cmndtable[*qtty], *tkns, len);
	(*qtty)++;
	return (0);
}

void	free_tables(t_parsing *cts)
{
	int	i;

	i = 0;
	while (!cts[i].islast)
	{
		free_cmndline(cts[i].cmndtable);
		free_cmndline(cts[i].ins);
		free_cmndline(cts[i].outs);
		i++;
	}
	free(cts);
}
