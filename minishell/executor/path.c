/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 14:14:53 by phijano-          #+#    #+#             */
/*   Updated: 2023/11/28 15:34:27 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ft_check_memory_error(void *pnt)
{
	if (!pnt)
	{
		perror("Error\n");
		exit(1);
	}
}

int static	ft_has_path(char *cmd)
{
	int	count;
	int	bar;
	int	no_path;

	if (!cmd)
		return (0);
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
	ft_check_memory_error(path);
	count = -1;
	while (path[++count])
	{
		temp = path[count];
		path[count] = ft_strjoin(path[count], "/");
		ft_check_memory_error(path[count]);
		free(temp);
	}
	return (path);
}

char static	*ft_get_env_path(char **envp)
{
	int		c;
	char	*full_path;

	full_path = NULL;
	c = -1;
	while (envp[++c])
	{
		if (ft_strncmp(envp[c], "PATH", 4) == 0)
		{
			full_path = ft_substr(envp[c], 5, ft_strlen(envp[c]) - 5);
			ft_check_memory_error(full_path);
		}
	}
	if (!ft_has_path(full_path))
	{
		free(full_path);
		full_path = ft_strdup(".");
		ft_check_memory_error(full_path);
	}
	return (full_path);
}

char	**ft_get_path(char **envp)
{
	char	*full_path;
	char	**path;

	path = NULL;
	if (envp[0])
		full_path = ft_get_env_path(envp);
	path = ft_fix_path(full_path);
	free(full_path);
	return (path);
}
