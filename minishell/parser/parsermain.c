/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:47:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/12 16:57:18 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "msparser.h"

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
	free_cmndline(tokenarr);
	return (cts);
}
