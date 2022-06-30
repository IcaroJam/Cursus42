/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:53:14 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/05/03 09:43:37 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*start;

	start = (char *) malloc(count * size);
	if (!start)
		return (0);
	ft_bzero(start, count * size);
	return ((void *)start);
}
