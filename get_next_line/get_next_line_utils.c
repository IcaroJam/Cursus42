/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:33:23 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/09 13:04:06 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(const char *buff, int *nlflag)
{
	size_t	ret;

	*nlflag = 0;
	ret = 0;
	while (buff[ret] && buff[ret] != '\n')
		ret++;
	if (buff[ret] == '\n')
		*nlflag = 1;
	return (ret + *nlflag);
}

size_t	ft_strlen(const char *s)
{
	size_t	ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

void	*ft_bcalloc(size_t count, size_t size)
{
	char	*start;
	char	*temp;

	start = malloc(count * size);
	if (!start)
		return (0);
	temp = start;
	while (count--)
		*temp++ = 0;
	return (start);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*ret;

	if (!s1 || !s2)
		return (0);
	len = ft_strlen(s1) + ft_strlen(s2);
	ret = (char *) malloc((len + 1) * sizeof(char));
	if (!ret)
		return (0);
	while (*s1)
		*ret++ = *s1++;
	while (*s2)
		*ret++ = *s2++;
	*ret = 0;
	return (ret - len);
}
