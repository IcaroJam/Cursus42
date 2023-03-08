/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecolours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 12:23:51 by ntamayo-          #+#    #+#             */
/*   Updated: 2023/03/08 13:26:51 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

static int	gethex(char *line)
{
	int	ret;
	int	i;

	ret = atouc(line, &i) << 16;
	if (line[i++] != ',')
		errexit("RGB elements must be separated by a comma.");
	while (ft_isspace(line[i]))
		i++;
	line += i;
	ret += atouc(line, &i) << 8;
	if (line[i++] != ',')
		errexit("RGB elements must be separated by a comma.");
	while (ft_isspace(line[i]))
		i++;
	line += i;
	ret += atouc(line, &i);
	return (ret);
}

void	getcolours(int colstored[2], char *line, t_cub *cub)
{
	int	*colourdir;

	while (ft_isspace(*line))
		line++;
	if (!colstored[0] && !ft_strncmp(line, "F", 1))
	{
		colourdir = &cub->mdata.floorc;
		colstored[0] = 1;
	}
	else if (!colstored[1] && !ft_strncmp(line, "C", 1))
	{
		colourdir = &cub->mdata.ceilic;
		colstored[1] = 1;
	}
	else
		errexit("Bad/dup colour identifier. Accepted: [F, C].");
	line++;
	while (ft_isspace(*line))
		line++;
	*colourdir = gethex(line);
}
