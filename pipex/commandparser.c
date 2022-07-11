/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commandparser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 15:55:27 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/07/11 15:03:26 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*commander(t_piper *piper, char **argv, int childpos)
{
	char	*temp;
	char	*ret;

	piper->currcmd = pipesplit(argv[childpos], ' ');
	if (!piper->currcmd)
		errxit("Error while retrieving command arguments.\n");
	if (ft_strchr(piper->currcmd[0], '/'))
		return (piper->currcmd[0]);
	if (!piper->paths)
		return (piper->currcmd[0]);
	while (*piper->paths)
	{
		temp = ft_strjoin(*piper->paths, "/");
		ret = ft_strjoin(temp, piper->currcmd[0]);
		if (!ret)
			return (NULL);
		if (!access(ret, 0))
			return (ret);
		free(temp);
		free(ret);
		piper->paths++;
	}
	return (NULL);
}
