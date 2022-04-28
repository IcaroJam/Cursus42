/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 21:34:53 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/28 11:53:58 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static const char	*ft_prep(const char *str, int *isneg)
{
	while ((*str >= 8 && *str <= 13) || *str == ' ')
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
