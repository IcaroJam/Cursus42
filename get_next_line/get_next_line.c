/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:49:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/06 17:57:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// If the content of the buffer is NULL it has already been completely
// processed and it should be read on again if possible.
static void	ft_buffprocess(int fd, char **buff)
{
	*buff -= BUFFER_SIZE;
	read(fd, *buff, BUFFER_SIZE);
}



static char	*ft_fragfetch(int fd, char **buff)
{
	char	*linfrag;
	size_t	fraglen;
	size_t	i;
	int		nlflag;

	fraglen = ft_linelen(*buff, &nlflag);
	linfrag = malloc(sizeof(char) * (fraglen + 1));
	if (!linfrag)
		return (NULL);
	i = 0;
	while (i < fraglen)
	{
		linfrag[i] = buff[0][i];
		i++;
	}
	linfrag[i] = 0;
	*buff += i;
	return (linfrag);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buff = NULL;
	int			eoflag;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	eoflag = 1;
	if (!buff)
	{
		buff = ft_bcalloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		eoflag = read(fd, buff, BUFFER_SIZE);
	}
	ret = ft_linefetch(fd, &buff);
	return (ret);
}

int	main(){
	int fd = open("coso.txt", O_RDONLY);
	char *line = get_next_line(fd);

	printf("%s", line);
}
