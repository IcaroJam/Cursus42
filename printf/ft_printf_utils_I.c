/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_I.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 15:50:43 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 15:55:07 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(char *str)
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
