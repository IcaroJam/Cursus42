/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/26 14:41:49 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;

static char	*prompter(const int argc, char **argv)
{
	char	*ret;

	ret = NULL;
	if (argc > 1)
		ret = ft_strjoin(argv[1], \
				"@\e[38;5;208mminishell ~ \e[38;5;220m$ \e[0m");
	if (!ret)
		ret = ft_strdup(\
				"pinche_perro@\e[38;5;208mminishell ~ \e[38;5;220m$ \e[0m");
	return (ret);
}

static char	**enviromentor(char **ogenv)
{
	char	**env;
	int		i;

	i = 0;
	while (ogenv[i])
		i++;
	env = ft_calloc(i + 2, sizeof(char *));
	if (!env)
		return (NULL);
	i = 0;
	while (ogenv[i + 1])
	{
		env[i] = ft_strdup(ogenv[i]);
		if (!env[i++])
			return (free_cmndline(env));
	}
	env[i++] = ft_strdup("?=0");
	env[i] = ft_strdup(ogenv[i - 1]);
	if (!env[i] || !env[i - 1])
		return (free_cmndline(env));
	return (env);
}

int	main(int argc, char **argv, char **envp)
{
	char		*prompt;
	char		*cmndline;
	t_parsing	*cts;

	signal(SIGINT, ft_ctrl_c);
	signal(SIGQUIT, SIG_IGN);
	cts = NULL;
	prompt = prompter(argc, argv);
	if (!prompt)
	{
		ft_putendl_fd("Error while initializing prompt.\n", 2);
		return (1);
	}
	g_env = enviromentor(envp);
	if (!g_env)
	{
		ft_putendl_fd("Error while initializing environment variable.\n", 2);
		return (1);
	}
	while (1)
	{
		cmndline = readline(prompt);
		if (!cmndline)
			exit(0);
		if (cmndline[0])
		{
			add_history(cmndline);
			cts = parse_line(cmndline);
			if (cts)
			{
			//if (!ft_strncmp(*cts[0].cmndtable, "exit", 5) && (!cts[1].cmndtable))
			if (!ft_strncmp(cmndline, "exit", 5))
				return (ms_exit(cts, cmndline, prompt));
			}
			ft_check_cmds(cts, envp);
			ft_executor(cts, envp);
			free_tables(cts);
		}
		free(cmndline);
	}
	return (0);
}
