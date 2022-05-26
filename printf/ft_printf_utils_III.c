/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_III.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:11:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/26 15:42:48 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char	*ptf_chars(t_flags flags, va_list list)
{
	char	*ret;
	int		c;

	flags.zero = 0;
	ret = malloc(sizeof(char));
	if (!ret)
		return (NULL);
	*ret = 0;
	c = va_arg(list, int);
	ret = ft_addchr(ret, c, 0);
	return (ret);
}

void	ptf_putstr(t_pbuff *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer->buff[i])
	{
		write(1, &buffer->buff[i], 1);
		i++;
	}
	free(buffer->buff);
}
