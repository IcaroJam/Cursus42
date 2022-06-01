/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_I.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:50:43 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/01 15:35:35 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	*ptf_zalloc(int len)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (i <= len)
		ret[i++] = 0;
	return (ret);
}

int	ptf_atoi(char const **str)
{
	int	ret;

	ret = 0;
	while (**str >= '0' && **str <= '9')
	{
		ret *= 10;
		ret += *(*str)++ - '0';
	}
	str[0]--;
	return (ret);
}

char	*ft_addchr(char *str, char const c, int currlen)
{
	char	*ret;
	int		i;

	i = 0;
	if (!str)
		return (NULL);
	ret = malloc(sizeof(char) * (currlen + 2));
	if (!ret)
		return (NULL);
	while (currlen)
	{
		*ret++ = str[i++];
		currlen--;
	}
	*ret++ = c;
	*ret = 0;
	free(str);
	return (ret - i - 1);
}

char	*ptf_strjoin(t_pbuff *buffer, char *str)
{
	int		slen;
	int		i;
	int		templen;
	char	*ret;

	i = 0;
	buffer->len = ptf_truelen(buffer);
	slen = ptf_strlen(str);
	ret = malloc(sizeof(char) * (buffer->len + slen + 1));
	if (!ret)
		return (NULL);
	templen = buffer->len;
	while (templen)
	{
		*ret++ = buffer->buff[i++];
		templen--;
	}
	while (*str)
		*ret++ = *str++;
	*ret = 0;
	free(buffer->buff);
	return (ret - buffer->len - slen);
}

char	*ft_concsection(t_pbuff *buffer, char const **str)
{
	int		slen;
	int		i;
	int		templen;
	char	*ret;

	i = 0;
	buffer->len = ptf_truelen(buffer);
	slen = ptf_sectlen(*str);
	ret = malloc(sizeof(char) * (buffer->len + slen + 1));
	if (!ret)
		return (NULL);
	templen = buffer->len;
	while (templen)
	{
		*ret++ = buffer->buff[i++];
		templen--;
	}
	while (**str && **str != '%')
		*ret++ = *(*str)++;
	*ret = 0;
	free(buffer->buff);
	return (ret - buffer->len - slen);
}
