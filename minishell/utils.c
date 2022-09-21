/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 13:55:53 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/21 15:41:13 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern char	**g_env;

char	*ms_getenv(const char *name)
{
	int	len;

	len = ft_strlen(name);
	while (*g_env)
	{
		if (!ft_strncmp(*g_env, name, len) && g_env[0][len] == '=')
			return (&g_env[0][len + 1]);
		g_env++;
	}
	return (NULL);
}

void	*free_cmndline(char **cmndline)
{
	int	i;

	i = 0;
	if (!cmndline)
		return (NULL);
	while (cmndline[i])
		free(cmndline[i++]);
	free(cmndline);
	return (NULL);
}

void	free_tables(t_parsing *cts)
{
	int	i;

	i = 0;
	if (!cts)
		return ;
	while (!cts[i].islast)
	{
		free_cmndline(cts[i].cmndtable);
		free_cmndline(cts[i].ins);
		free_cmndline(cts[i].outs);
		free(cts[i].iflgs);
		free(cts[i].oflgs);
		i++;
	}
	free(cts);
}
