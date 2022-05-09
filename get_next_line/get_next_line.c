/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:49:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/09 13:16:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

// If the content of the buffer is NULL it has already been completely
// processed and it should be read on again if possible.
static void	ft_buffprocess(int fd, char **buff, size_t bufflen)
{
	*buff -= bufflen;
	read(fd, *buff, BUFFER_SIZE);
}

static char	*ft_fragfetch(int *nlflag, char **buff, size_t *fraglen)
{
	char	*linfrag;
	size_t	i;

	*fraglen = ft_linelen(*buff, nlflag);
	linfrag = malloc(sizeof(char) * (*fraglen + 1));
	if (!linfrag)
		return (NULL);
	i = 0;
	while (i < *fraglen)
	{
		linfrag[i] = buff[0][i];
		i++;
	}
	linfrag[i] = 0;
	*buff += i;
	return (linfrag);
}

static char	*ft_fragconglomerator(int fd, char **buff)
{
	int		nlflag;
	size_t	bufflen;
	char	*ret;
	char	*temp;

	nlflag = 0;
	ret = ft_fragfetch(&nlflag, buff, &bufflen);
	if (!ret)
		return (NULL);
	while (!nlflag)
	{
		ft_buffprocess(fd, buff, bufflen);
		temp = ft_fragfetch(&nlflag, buff, &bufflen);
		ret = ft_strjoin(ret, temp);
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buff = NULL;
	int			eoflag;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!buff)
	{
		buff = ft_bcalloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		eoflag = read(fd, buff, BUFFER_SIZE);
	}
	ret = ft_fragconglomerator(fd, &buff);
	return (ret);
}

int	main(){
	int fd = open("coso.txt", O_RDONLY);
	char *line;

	for (int i = 0; i < 6; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
}
