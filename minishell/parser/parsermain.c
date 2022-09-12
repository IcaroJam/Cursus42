/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:47:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/12 19:43:22 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
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

t_parsing	*parse_line(char *line)
{
	char		**tokenarr;
	t_parsing	*cts;

	tokenarr = tokenize_line(line);
	if (!tokenarr)
		return (NULL);
	//
	/** for (int i = 0; tokenarr[i]; i++)
	  *     printf("%s\n", tokenarr[i]); */
	//
	// Allocate space for an array of len (tkns) and type t_parsing.
	//
	//printf("You introduced %d commands.\n", get_numocmds((const char **)tokenarr));
	cts = ft_calloc(get_ncmds((const char **)tokenarr) + 1, sizeof(t_parsing));
	if (cts)
	{
		// Do stuff. If calloc returned NULL, jump straight to freeing.
	}
	free_cmndline(tokenarr);
	return (cts);
}
