/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 12:50:35 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/06/20 13:05:25 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	printerror(char *msg)
{
	printf("Error\n%s", msg);
	system("leaks so_long");
	exit(1);
}

void	maperror(t_map *map, char *msg)
{
	free(map->str);
	printerror(msg);
}
