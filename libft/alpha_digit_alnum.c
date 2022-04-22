/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alpha_digit_alnum.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 13:32:10 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/04/22 20:39:34 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) || ft_isalpha(c))
		return (1);
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>

int main(void)
{
	printf("%d %d %d %d %d %d\n", ft_isalpha(57), 
	isalpha(57), ft_isdigit(57), isdigit(57), ft_isalnum(57), isalnum(57));
}*/
