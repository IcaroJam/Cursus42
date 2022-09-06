/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsermain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:47:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/06 17:19:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

// The line inputed into the shell is divided into "tokens" (words) that are
// then grouped into a command table, of which the first two lines are always
// the input and output filedrescriptors respectively.
t_parsing	parse_line(char *line)
{
	t_parsing	ret;
	char		**tokenarr;

	tokenarr = tokenize_line(line);
	if (!tokenarr)
	{
		perror("Error: ");
		return (NULL);
	}
	// Remember to free the strings of tokenarr and tokenarr itself
	return (ret);
}
