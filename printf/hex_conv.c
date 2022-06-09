/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 10:49:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/09 14:00:11 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	int	i;

	i = 0;
	while (i < 7)
	{
		if (num[i] != '0')
			break ;
		i++;
	}
	lens->num = 8 - i;
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
		ret[--i] = base[num % 16];
		num /= 16;
	}
	return (ret);
}

void static	hexbuilder(t_flags flags, t_digitlens lens, char **ret, char **temp)
{
	int	i;
	int	j;

	i = 0;
	j = 8 - lens.num;
	if (!flags.dash)
		while (lens.spaces--)
			ret[0][i++] = ' ';
	if (flags.hash)
	{
		ret[0][i++] = '0';
		ret[0][i++] = 'x';
	}
	while (lens.num--)
		ret[0][i++] = temp[0][j++];
	free(temp[0]);
	temp[0] = NULL;
	if (flags.dash)
		while (lens.spaces--)
			ret[0][i++] = ' ';
}

char	*ptf_hex(t_flags flags, va_list list)
{
	char		*temp;
	char		*ret;
	t_digitlens	lens;

	temp = hexnum(va_arg(list, unsigned int), "0123456789abcdef");
	if (!temp)
		return (NULL);
	hexlen(flags, &lens, temp);
	ret = ptf_zalloc(lens.total);
	if (!ret)
		return (NULL);
	hexbuilder(flags, lens, &ret, &temp);
	if (flags.conv == 'X')
		ptf_toupper(ret);
	return (ret);
}
