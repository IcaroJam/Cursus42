/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/19 19:44:00 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_row(char **row)
{
	int	i;

	i = 0;
	while (row[i])
	{
		printf("\"%s\" ", row[i++]);
	}
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
		printf("\nOuts: ");
		print_row(cts[i++].outs);
		printf("\n");
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

int	main(int argc, char **argv, char **envp)
{
	char		*prompt;
	char		*cmndline;
	t_parsing	*cts;

	cts = NULL;
	prompt = prompter(argc, argv);
	while (1)
	{
		cmndline = readline(prompt);
		// Handle signals here.
		if (cmndline[0])
		{
			add_history(cmndline);
			if (!ft_strncmp(cmndline, "exit", 5))
				break ;
			cts = parse_line(cmndline);
			if (cts)
				print_table(cts);
			if (!ft_strncmp(cmndline, "env", 4))
				ms_env(envp);
			// What if cts == NULL?
			// Free cts when finished with it AND when exiting.
		}
		// Before executing command, check wether it is builtin or not.
		free(cmndline);
	}
	//
	system("leaks minishell");
	//
	return (0);
}
