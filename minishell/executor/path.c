/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:14:53 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/06 15:51:19 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_has_path(char *cmd)
{
	int	count;
	int	bar;
	int	no_path;

	bar = 0;
	no_path = 0;
	count = -1;
	while (cmd[++count])
	{
		if (cmd[count] == '\"' || cmd[count] == '\'' || cmd[count] == ' ')
			no_path = 1;
		if (cmd[count] == '/' && no_path == 0)
			bar = 1;
	}
	return (bar);
}

char static	**ft_fix_path(char *full_path)
{
	char	**path;
	char	*temp;
	int		count;

	path = ft_split(full_path, ':');
	count = -1;
	while (path[++count])
	{
		temp = path[count];
		path[count] = ft_strjoin(path[count], "/");
		free(temp);
	}
	return (path);
}

char	**ft_get_path(char **envp)
{
	int		c;
	char	*full_path;
	char	**path;
	int		bar;

	bar = 0;
	path = NULL;
	c = -1;
	if (envp[0])
	{
		while (envp[++c])
			if (ft_strncmp(envp[c], "PATH", 4) == 0)
				full_path = ft_substr(envp[c], 5, ft_strlen(envp[c]) - 5);
		bar = ft_has_path(full_path);
		if (bar == 0)
			full_path = ft_strdup(".");
	}
	else
		full_path = ft_substr(PTH, 5, ft_strlen(PTH) - 5);
	path = ft_fix_path(full_path);
	free(full_path);
	return (path);
}
