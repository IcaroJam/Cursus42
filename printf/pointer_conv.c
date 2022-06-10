/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:38:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/10 12:30:46 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char static	*ptrnum(unsigned long num, char *base)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * 13);
	if (!ret)
		return (NULL);
	i = 0;
	ret[12] = 0;
	while (i < 12)
		ret[i++] = '0';
	while (num > 0)
	{
		ret[--i] = base[num % 16];
		num /= 16;
	}
	return (ret);
}

void static	ptrlen(t_flags flags, t_digitlens *lens, char *num)
{
	lens->num = 0;
	while (*num)
	{
		if (*num != '0')
			break ;
		num++;
		lens->num++;
	}
	lens->num = 12 - lens->num;
	lens->sign = 2;
	lens->spaces = 0;
	if (flags.minfw > lens->num + lens->sign)
		lens->spaces = flags.minfw - lens->num - lens->sign;
	lens->total = lens->spaces + lens->num + lens->sign;
}

void static ptrbuilder(t_flags flags, t_digitlens lens, char *ret, char *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 12 - lens.num;
	if (!flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
	ret[i++] = '0';
	ret[i++] = 'x';
	while (lens.num--)
		ret[i++] = temp[j++];
	if (flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
}

char	*ptf_pointer(t_flags flags, va_list list)
{
	char		*ret;
	char		*temp;
	t_digitlens	lens;

	temp = ptrnum(va_arg(list, unsigned long), "0123456789abcdef");
	if (!temp)
		return (NULL);
	ptrlen(flags, &lens, temp);
	ret = ptf_zalloc(lens.total);
	if (!ret)
		return (NULL);
	ptrbuilder(flags, lens, ret, temp);
	free(temp);
	temp = NULL;
	return (ret);
}
