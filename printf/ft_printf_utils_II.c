/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_II.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:13:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/23 16:27:00 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_isflag(char const c)
{
	if (c == '-' || c == '0' || c == '.')
		return (1);
	if (c >= '1' && c <= '9')
		return (1);
	if (c == '#' || c == ' ' || c == '+')
		return (1);
	return (0);
}
