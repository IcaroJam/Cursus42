/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:49:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/06 12:31:44 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>

static void	ft_buffprocess(int fd, char **buff)
{
	if ()
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buff = NULL;

	if (fd <= 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!buff)
		buff = ft_calloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	ft_buffprocess(fd, &buff);
	//read(fd, buff, BUFFER_SIZE);

//	printf("%s", buff);
	return (ret);
}

/** int	main(){
  *     get_next_line(1);
  * } */
