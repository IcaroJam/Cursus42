/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexingutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/09 12:14:12 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"
#include "msparser.h"

int	isredir(const char c)
{
	return (c == '<' || c == '>' || c == '|');
}

void	free_cmndline(char **cmndline)
{
	int	i;

	i = 0;
	while (cmndline[i])
		free(cmndline[i++]);
	free(cmndline);
}

int	check_redirerr(const char **tkns)
{
	if (!tkns[0])
		return (0);
	if (isredir(tkns[0][0]) && !tkns[1])
		return (1);
	tkns++;
	while (*tkns)
	{
		if ((isredir(tkns[-1][0]) && isredir(tkns[0][0]))
			|| (isredir(tkns[0][0]) && !tkns[1]))
			return (1);
		tkns++;
	}
	return (0);
}
