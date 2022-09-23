/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/23 16:45:08 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//char	**g_env;

//
static void	print_row(char **row)
{
	int	i;

	i = 0;
	while (row[i])
		printf("\"%s\" ", row[i++]);
}

static void	printf_flags(char **strarr, int *row)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (strarr[len])
		len++;
	while (i < len)
		printf("%d ", row[i++]);
}

static void	print_table(t_parsing *cts)
{
	int	i;

	i = 0;
	while (!cts[i].islast)
	{
		printf("Cmnds: ");
		print_row(cts[i].cmndtable);
		printf("\nIns: ");
		print_row(cts[i].ins);
		printf("\nInflags: ");
		printf_flags(cts[i].ins, cts[i].iflgs);
		printf("\nOuts: ");
		print_row(cts[i].outs);
		printf("\nOutflags: ");
		printf_flags(cts[i].outs, cts[i].oflgs);
		printf("\n");
		i++;
	}
}

static char	*prompter(const int argc, char **argv)
{
	char	*ret;

	ret = NULL;
	if (argc > 1)
		ret = ft_strjoin(argv[1], "@minishell ~ $ ");
	if (!ret)
		ret = "pinche_perro@minishell~ $ ";
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
	//signal(SIGQUIT, ft_ctrl_backslash); para hacer funcion Ctrl + \ ?
	signal(SIGQUIT, SIG_IGN);//para ignorarlo
	//signal(SIGQUIT, SIG_DFL);//el manejador por defecto, para que mate el proceso. hara falta para los child?

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

		if (!cmndline)//Ctrl + D
			exit(0);//liberar memoria

		if (cmndline[0])
		{
			add_history(cmndline);
			cts = parse_line(cmndline);
			if (cts)
			{
				if (!ft_strncmp(cmndline, "exit", 5))
					return (ms_exit(cts, cmndline, prompt));
				print_table(cts);
				// What if cts == NULL?
				// Free cts when finished with it AND when exiting.
			}
		}
		// Before executing command, check wether it is builtin or not.
		ft_check_cmds(cts, envp);// mirar si cabe en el executor para limpiar algo el main
		ft_executor(cts, envp);
		free_tables(cts);
		free(cmndline);
	}
	return (0);
}
