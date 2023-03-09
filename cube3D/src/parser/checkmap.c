/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:25:33 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/09 12:05:37 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

// Saltarse espacios.
// Encontrar 1.
// Volver a saltar o encontrar char válido.
// Comprobar que el válido no tenga espacios adyacentes
// o que no esté en la primera o última línea.
// Repetir hasta llegar al final de la línea.

static int	isvalid(char c)
{
	return (c == '1' || c == '0'
		|| c == 'N' || c == 'W' || c == 'S' || c == 'E');
}

static void	charcheck(char *line, unsigned int i, unsigned int lo, t_cub *cub)
{
	if (!line[i])
		return ;
	if (!isvalid(line[i]))
		frerrxit("Illegal tile found in the map.", cub);
	if ((line[i] != '1' && (!line[i + 1] || line[i + 1] == ' '))
		|| (line[i] != '1' && (!lo || lo == cub->mdata.ysize - 1))
		|| (lo > 0
			&& line[i] != '1' && !isvalid(cub->mdata.cmap[lo - 1][i]))
		|| (lo < cub->mdata.ysize - 1
			&& line[i] != '1' && !isvalid(cub->mdata.cmap[lo + 1][i])))
		frerrxit("Map isn't closed.", cub);
}

// For each character of the line:
// Skip spaces until a 1 is found. If anything else is found after spaces,
// throw an error.
// Check if the character is valid.
// If it is BUT it isn't a 1, check wether it is the last char in the line
// or there is a space after it. Also check if we are looking at the first or
// last line, since those can only have spaces or 1s. Finally, if we aren't
// on the first or last line, check if the character over or under isn't valid.

static void	checkline(char *line, unsigned int lineno, t_cub *cub)
{
	unsigned int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			while (line[i] == ' ')
				i++;
			if (!line[i])
				continue ;
			else if (line[i] != '1')
				frerrxit("Illegal tile found after space.", cub);
		}
		charcheck(line, i, lineno, cub);
		i++;
	}
}

void	checkmap(char **map, t_cub *cub)
{
	unsigned int	i;

	i = 0;
	while (map[i])
	{
		checkline(map[i], i, cub);
		i++;
	}
}
