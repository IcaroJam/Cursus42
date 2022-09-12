/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:47:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/12 13:47:44 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "msparser.h"

t_parsing	*parse_line(char *line)
{
	t_parsing	*ret = NULL;
	char		**tokenarr;

	tokenarr = tokenize_line(line);
	if (!tokenarr)
	{
		perror("Error");
		return (ret);
	}
	//
	for (int i = 0; tokenarr[i]; i++)
	    printf("%s\n", tokenarr[i]);
	//
	free_cmndline(tokenarr);
	return (ret);
}
