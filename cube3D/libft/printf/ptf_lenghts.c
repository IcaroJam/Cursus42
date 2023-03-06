/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_lenghts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 17:06:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/31 17:10:10 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ptf_strlen(char const *str)
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

int	ptf_truelen(t_pbuff *buffer)
{
	int		nullnum;
	int		ret;

	nullnum = buffer->nulls;
	ret = 0;
	while (nullnum)
	{
		while (buffer->buff[ret])
			ret++;
		ret++;
		nullnum--;
	}
	ret += ptf_strlen(&buffer->buff[ret]);
	return (ret);
}
