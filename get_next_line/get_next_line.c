/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:49:42 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/11 17:21:03 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include <stdio.h>
//#include <fcntl.h>

// If the content of the buffer is NULL it has already been completely
// processed and it should be read on again if possible.
size_t	ft_buffprocess(int fd, char **buff, size_t *bufflen)
{
	*buff -= BUFFER_SIZE - *bufflen;
	*bufflen = read(fd, *buff, BUFFER_SIZE);
	if (!*bufflen)
		return (0);
	buff[0][*bufflen - 1] = 0;
	return (*bufflen);
}

char	*ft_fragfetch(int *nlflag, char **buff)
{
	char	*linfrag;
	size_t	i;
	size_t	fraglen;

	fraglen = ft_linelen(*buff, nlflag);
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

char	*ft_fragconglomerator(int fd, char **buff)
{
	int		nlflag;
	size_t	eoflag;
	char	*ret;
	char	*temp;

	nlflag = 0;
	eoflag = ft_strlen(*buff);
	ret = ft_fragfetch(&nlflag, buff);
	if (!ret)
		return (NULL);
	while (!nlflag || eoflag < BUFFER_SIZE)
	{
		eoflag = ft_buffprocess(fd, buff, &eoflag);
		temp = ft_fragfetch(&nlflag, buff);
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

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	if (!buff)
	{
		buff = ft_bcalloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buff)
			return (NULL);
		if (!read(fd, buff, BUFFER_SIZE))
			return (NULL);
	}
	ret = ft_fragconglomerator(fd, &buff);
	return (ret);
}
/** 
  * int	main(){
  *     int fd = open("coso.txt", O_RDONLY);
  *     char *line;
  *
  * //	line = get_next_line(fd);
  *     for (int i = 0; i < 12; i++)
  *     {
  *         line = get_next_line(fd);
  *         printf("%s", line);
  *         free(line);
  *     }
  *     system("leaks a.out");
  * } */
