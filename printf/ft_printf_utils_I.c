/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_I.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:50:43 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/26 15:17:02 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char const *str)
{
	int	ret;

	ret = 0;
	while (str[ret])
		ret++;
	return (ret);
}

int	ptf_sectlen(char const *str)
{
	int	ret;

	ret = 0;
	while (str[ret] && str[ret] != '%')
		ret++;
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
	return (ret);
}

char	*ptf_strjoin(char *finalstr, char *str)
{
	int		fslen;
	int		slen;
	char	*ret;

	if (!finalstr || !str)
		return (NULL);
	fslen = ft_strlen(finalstr);
	slen = ft_strlen(str);
	ret = malloc(sizeof(char) * (fslen + slen + 1));
	if (!ret)
		return (NULL);
	while (*finalstr)
		*ret++ = *finalstr++;
	while (*str)
		*ret++ = *str++;
	*ret = 0;
	free(finalstr - fslen);
	return (ret - fslen - slen);
}

char	*ft_concsection(char *finalstr, char const **str)
{
	int		fslen;
	int		slen;
	char	*ret;

	if (!finalstr || !*str)
		return (NULL);
	fslen = ft_strlen(finalstr);
	slen = ptf_sectlen(*str);
	ret = malloc(sizeof(char) * (fslen + slen + 1));
	if (!ret)
		return (NULL);
	while (*finalstr)
		*ret++ = *finalstr++;
	while (**str && **str != '%')
		*ret++ = *(*str)++;
	*ret = 0;
	free(finalstr - fslen);
	return (ret - fslen - slen);
}
