/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ioverflw.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 12:37:36 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/12/24 18:47:33 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_ioverflw(char *str)
{
	int	len;
	int	num;

	num = ft_atoi(str);
	len = ft_strlen(str);
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		return (!num || len > 11 || (len == 11 && str[1] > '2'));
	return (num == -1 || len > 10 || (len == 10 && str[0] > '2'));
}
