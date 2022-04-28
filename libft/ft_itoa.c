/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 15:09:47 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/28 11:05:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static unsigned int	ft_prepnum(int n, int *isneg)
{
	unsigned int	temp;

	*isneg = 0;
	if (n < 0)
	{
		*isneg = 1;
		temp = -n;
	}
	else
		temp = n;
	return (temp);
}

char	*ft_itoa(int n)
{
	char				*ret;
	int					numlen;
	unsigned int		temp;
	int					isneg;

	numlen = 0;
	if (!n)
		numlen = 1;
	temp = ft_prepnum(n, &isneg);
	while (n)
	{
		n /= 10;
		numlen++;
	}
	ret = ft_calloc(numlen + isneg + 1, sizeof(char));
	if (!ret)
		return (NULL);
	if (isneg)
		*ret = '-';
	while (numlen)
	{
		ret[numlen-- - !isneg] = temp % 10 + '0';
		temp /= 10;
	}
	return (ret);
}
