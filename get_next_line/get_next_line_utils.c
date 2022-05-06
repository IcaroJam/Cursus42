/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 12:33:23 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/06 12:36:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_bcalloc(size_t count, size_t size)
{
	char	*start;
	char	*temp;

	start = malloc(count * size);
	if (!start)
		return (0);
	temp = start;
	while (size--)
		*temp++ = 0;
	return (start);
}
