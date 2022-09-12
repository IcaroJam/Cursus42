/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:47:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/12 18:10:27 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "msparser.h"

static int	get_numocmds(const char **tokenarr)
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
	t_parsing	*cts = NULL;

	tokenarr = tokenize_line(line);
	if (!tokenarr)
		return (NULL);
	//
	for (int i = 0; tokenarr[i]; i++)
	    printf("%s\n", tokenarr[i]);
	//
	// Allocate space for an array of len (tkns) and type t_parsing.
	//
	printf("You introduced %d commands.\n", get_numocmds((const char **)tokenarr));
	free_cmndline(tokenarr);
	return (cts);
}
