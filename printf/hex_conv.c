/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/09 12:12:26 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdlib.h>

void static	ptf_toupper(char *str)
{
	while (*str)
	{
		if (*str >= 'a' && *str <= 'z')
			*str -= 32;
		str++;
	}
}

void static	hexlen(t_flags flags, t_digitlens *lens, char *num)
{
	lens->num = ptf_strlen(num);
	lens->sign = 0;
	lens->spaces = 0;
	if (flags.hash)
		lens->sign = 2;
	if (flags.minfw > lens->num + lens->sign)
		lens->spaces = flags.minfw - lens->num - lens->spaces;
	lens->total = lens->spaces + lens->sign + lens->num;
}

char static	*hexnum(unsigned int num, char *base)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * 9);
	if (!ret)
		return (NULL);
	i = 0;
	ret[8] = 0;
	while (i < 8)
		ret[i++] = '0';
	while (num > 0)
	{
		ret[i--] = base[num % 16];
		num /= 16;
	}
	return (ret);
}

char	*ptf_hex(t_flags flags, va_list list)
{
	char		*temp;
	char		*ret;
	t_digitlens	lens;

	temp = hexnum(va_arg(list, unsigned int), "0123456789abcdef");
	if (!temp)
		return (NULL);
	if (flags.conv == 'X')
		ptf_toupper(ret);
	return (ret);
}
