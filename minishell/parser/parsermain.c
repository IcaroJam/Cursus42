/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:47:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/13 13:59:57 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "msparser.h"

static int	get_ncmds(const char **tokenarr)
{
	int	ret;

	ret = 1;
	while (*tokenarr)
	{
		if (tokenarr[1] && isredir(tokenarr[1][0]))
		{
			if (tokenarr[1][0] != '|')
				tokenarr++;
			else
				ret++;
			tokenarr++;
		}
		tokenarr++;
	}
	return (ret);
}

static void	tablecount(int arr[3], const char **tkns, int *i)
{
	arr[0] = 0;
	arr[1] = 0;
	arr[2] = 0;
	while (tkns[*i] && tkns[*i][0] != '|')
	{
		if (tkns[*i][0] == '<' || tkns[*i][0] == '>')
		{
			if (tkns[*i][0] == '<')
				arr[1]++;
			else
				arr[2]++;
			(*i)++;
		}
		else
			arr[0]++;
		(*i)++;
	}
	if (tkns[*i] && tkns[*i][0] == '|')
		(*i)++;
}

/** static int	stuff_rows(t_parsing *cts, const char **tkns)
  * {
  *     return (0);
  * } */

static int	fill_tables(t_parsing *cts, const int numocmds, const char **tkns)
{
	int	i;
	int	j;
	int	arr[3];

	i = 0;
	j = 0;
	while (i < numocmds)
	{
		tablecount(arr, tkns, &j);
		cts[i].cmndtable = ft_calloc(arr[0] + 1, sizeof(char *));
		cts[i].ins = ft_calloc(arr[1] + 1, sizeof(char *));
		cts[i].outs = ft_calloc(arr[2] + 1, sizeof(char *));
		cts[i].islast = 0;
		if (!cts[i].cmndtable || !cts[i].ins || !cts[i].outs)
		{
			cts[i].islast = 1;
			return (1);
		}
		// Stuff_rows should really be here.
		i++;
	}
	cts[i - 1].islast = 1;
	return (0);
}

t_parsing	*parse_line(char *line)
{
	int			numocmds;
	char		**tokenarr;
	t_parsing	*cts;

	tokenarr = tokenize_line(line);
	if (!tokenarr)
		return (NULL);
	/** for (int i = 0; tokenarr[i]; i++)
	  *     printf("%s\n", tokenarr[i]); */
	numocmds = get_ncmds((const char **)tokenarr);
	cts = malloc(sizeof(t_parsing) * numocmds);
	if (cts)
	{
		// Do stuff. If calloc returned NULL, jump straight to freeing.
		// Expand $ UNLESS it is inside single quotes. A single $ will always print $.
		if (fill_tables(cts, numocmds, (const char **)tokenarr))
		{
			perror("Error");
			free_tables(cts);
			return (NULL);
		}
	}
	else
		perror("Error");
	free_cmndline(tokenarr);
	return (cts);
}
