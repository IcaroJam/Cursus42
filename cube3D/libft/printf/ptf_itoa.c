/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_itoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:43:16 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/09 10:42:32 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ptf_prepnum(int n, int *isneg)
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

char	*ptf_itoa(int n)
{
	char			*ret;
	int				numlen;
	unsigned int	temp;
	int				isneg;

	numlen = 0;
	if (!n)
		numlen = 1;
	temp = ptf_prepnum(n, &isneg);
	while (n)
	{
		n /= 10;
		numlen++;
	}
	ret = ptf_zalloc(sizeof(char) * (numlen + isneg));
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

char	*ptf_utoa(unsigned int n)
{
	char			*ret;
	int				numlen;
	unsigned int	temp;

	numlen = 0;
	if (!n)
		numlen = 1;
	temp = n;
	while (n)
	{
		n /= 10;
		numlen++;
	}
	ret = ptf_zalloc(sizeof(char) * numlen);
	if (!ret)
		return (NULL);
	while (numlen--)
	{
		ret[numlen] = temp % 10 + '0';
		temp /= 10;
	}
	return (ret);
}
