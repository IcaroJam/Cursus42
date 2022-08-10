/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/10 16:21:23 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/08/10 16:22:51 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*ft_prep(const char *str, int *isneg)
{
	while ((*str > '\b' && *str < 14) || *str == ' ')
		str++;
	if (*str == '-')
	{
		*isneg = 1;
		str++;
	}
	else if (*str == '+')
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int	isneg;
	int	ret;

	isneg = 0;
	ret = 0;
	str = ft_prep(str, &isneg);
	while (*str >= '0' && *str <= '9')
	{
		ret *= 10;
		ret += *str++ - '0';
	}
	if (isneg)
		ret *= -1;
	if (isneg && ret > 0)
		return (0);
	if (!isneg && ret < 0)
		return (-1);
	return (ret);
}

int	ft_strlen(const char *s)
{
	int	ret;

	ret = 0;
	while (s[ret])
		ret++;
	return (ret);
}

int	ft_ioverflw(char *str)
{
	int	len;
	int	num;

	num = ft_atoi(str);
	len = ft_strlen(str);
	if (*str == '-')
		if (!num || len > 11 || (len == 11 && str[1] > '2'))
			return (1);
	if (*str != '-')
		if (num == -1 || len > 10 || (len == 10 && str[0] > '2'))
			return (1);
	return (0);
}
