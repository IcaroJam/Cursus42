/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:38:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/10 13:30:31 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char static	*ptrnum(unsigned long num, char *base)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * 17);
	if (!ret)
		return (NULL);
	i = 0;
	ret[16] = 0;
	while (i < 16)
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
	if (lens->num == 16)
		lens->num = 1;
	else
		lens->num = 16 - lens->num;
	lens->sign = 2;
	lens->spaces = 0;
	if (flags.minfw > lens->num + lens->sign)
		lens->spaces = flags.minfw - lens->num - lens->sign;
	lens->total = lens->spaces + lens->num + lens->sign;
}

void static	ptrbuilder(t_flags flags, t_digitlens lens, char *ret, char *temp)
{
	int	i;
	int	j;

	i = 0;
	j = 16 - lens.num;
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
	void		*conv;

	conv = va_arg(list, void *);
	temp = ptrnum((unsigned long) conv, "0123456789abcdef");
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
