/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:33:23 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/06 17:52:38 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_linelen(const char *buff, int *fragflag)
{
	size_t	ret;
	int		nl;

	nl = 0;
	ret = 0;
	while (buff[ret] && buff[ret] != '\n')
		ret++;
	if (buff[ret] == '\n')
		nl = 1;
	*fragflag = !nl;
	return (ret + nl);
}

size_t	ft_bufflen(const char *s)
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
