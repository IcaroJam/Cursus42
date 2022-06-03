/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_IV.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:19:49 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/03 18:17:43 by ntamayo-         ###   ########.fr       */
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

char static	*ptf_itoa(int n)
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
	ret = ptf_zalloc(sizeof(char) * (numlen + isneg + 1));
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

char	*ptf_digit(t_flags flags, va_list list)
{
	char	*ret;
	char	*temp;
	int		inplen;
	int		isneg;

	temp = ptf_itoa(va_arg(list, int));
	if (!temp)
		return (NULL);
	inplen = ptf_strlen(ret);
	isneg = 0;
	if (*ret == '-')
		isneg = 1;
	if (flags.minfw < (unsigned int) inplen)
		flags.minfw = inplen;
	return (ret);
}

// SEPARADOR // SIGNO/ESPACIO // RELLENO DE PCS // NUM // SEPARADOR
