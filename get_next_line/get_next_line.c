/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:49:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/09 18:53:20 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>

// If the content of the buffer is NULL it has already been completely
// processed and it should be read on again if possible.
int	ft_buffprocess(int fd, char **buff, size_t bufflen)
{
	*buff -= bufflen;
	if (!read(fd, *buff, BUFFER_SIZE))
		return (0);
	return (1);
}

char	*ft_fragfetch(int *nlflag, char **buff, size_t *fraglen)
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

char	*ft_fragconglomerator(int fd, char **buff)
{
	int		nlflag;
	int		eoflag;
	size_t	bufflen;
	char	*ret;
	char	*temp;

	nlflag = 0;
	ret = ft_fragfetch(&nlflag, buff, &bufflen);
	if (!ret)
		return (NULL);
	while (!nlflag)
	{
		eoflag = ft_buffprocess(fd, buff, bufflen);
		temp = ft_fragfetch(&nlflag, buff, &bufflen);
		ret = ft_strjoin(ret, temp);
		if (!eoflag)
			break ;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*ret;
	static char	*buff = NULL;
	int			eoflag;

	eoflag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!buff)
	{
		buff = ft_bcalloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		eoflag = read(fd, buff, BUFFER_SIZE);
	}
	if (!eoflag)
		return (NULL);
	ret = ft_fragconglomerator(fd, &buff);
	return (ret);
}

/*int	main(){
	int fd = open("coso.txt", O_RDONLY);
	char *line;

	for (int i = 0; i < 6; i++)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
}*/
