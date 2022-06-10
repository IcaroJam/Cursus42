/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pointer_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 11:38:58 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/10 12:03:44 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

char static	*ptrnum(unsigned long num, char *base)
{
	char	*ret;
	int		i;

	ret = malloc(sizeof(char) * 15);
	if (!ret)
		return (NULL);
	i = 2;
	ret[0] = '0';
	ret[1] = 'x';
	ret[14] = 0;
	while (i < 14)
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
	lens->num = ptf_strlen(num);
	lens->spaces = 0;
	if (flags.minfw > lens->num)
		lens->spaces = flags.minfw - lens->num;
	lens->total = lens->spaces + lens->num;
}

char	*ptf_pointer(t_flags flags, va_list list)
{
	char		*ret;
	char		*temp;
	t_digitlens	lens;
	int			i;

	temp = ptrnum(va_arg(list, unsigned long), "0123456789abcdef");
	if (!temp)
		return (NULL);
	ptrlen(flags, &lens, temp);
	ret = ptf_zalloc(lens.total);
	if (!ret)
		return (NULL);
	i = 0;
	if (!flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
	while (lens.num--)
		ret[i++] = *temp++;
	if (flags.dash)
		while (lens.spaces--)
			ret[i++] = ' ';
	free(temp - lens.num);
	temp = NULL;
	return (ret);
}
