/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atouc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senari <ntamayo-@student.42malaga.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:55:33 by senari            #+#    #+#             */
/*   Updated: 2023/03/04 16:06:24 by senari           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cubert.h"

int	atouc(const char *s, int *offset)
{
	int	ret;
	int	i;

	ret = 0;
	i = 0;
	while (ft_isdigit(s[i]))
	{
		ret *= 10;
		ret += s[i] - '0';
		if (ret > 255)
			return (-1);
		i++;
	}
	*offset = i;
	return (ret);
}
