/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 19:19:22 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/22 18:16:48 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static int	envrem(const char *var, char **env)
{
	int	i;
	int	len;

	if (!var)
		return (1);
	i = 0;
	len = ft_strlen(var);
	while (env[i] && !(!ft_strncmp(env[i], var, len) && env[i][len] == '='))
		i++;
	free(env[i]);
	while (env[i])
	{
		env[i] = env[i + 1];
		i++;
	}
	return (0);
}

static char	**envadd(const char *var, char **env)
{
	int		len;
	int		i;
	char	**tmp;

	len = 0;
	i = 0;
	while (env[len])
		len++;
	tmp = ft_calloc(len-- + 2, sizeof(char *));
	if (!tmp)
		return (NULL);
	while (i < len)
	{
		tmp[i] = env[i];
		i++;
	}
	tmp[i] = ft_strdup(var);
	if (!tmp[i++])
	{
		free(tmp);
		return (NULL);
	}
	tmp[i] = env[len];
	return (tmp);
}

int	ms_export(const char *var, char ***env)
{
	char	**tmp;

	if (!ft_strchr(var, '='))
	{
		ft_putendl_fd("Error: Exported var must have a value assigned.", 2);
		return (1);
	}
	tmp = envadd(var, *env);
	if (!tmp)
	{
		perror("Error");
		return (1);
	}
	free(*env);
	*env = tmp;
	return (0);
}

int	ms_unset(const char **vars, char **env)
{
	if (!vars || !*vars)
		return (1);
	vars++;
	while (*vars)
	{
		if (envrem(*vars, env))
			return (1);
		vars++;
	}
	return (0);
}

int	ms_env(char **env)
{
	int	i;

	i = 0;
	if (!env)
		return (1);
	while (env[i])
		ft_putendl_fd(env[i++], 1);
	return (0);
}
