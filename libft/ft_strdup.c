/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 13:18:30 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/26 13:45:20 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*start;
	size_t	len;

	len = ft_strlen(s1);
	start = (char *) malloc((len + 1) * sizeof(char));
	if (!start)
		return (0);
	ft_strlcpy(start, s1, len + 1);
	return (start);
}
