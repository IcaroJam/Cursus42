/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexingutils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 15:40:41 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/07 17:04:09 by ntamayo-         ###   ########.fr       */
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
		free(cmndline[i]);
	free(cmndline);
}
