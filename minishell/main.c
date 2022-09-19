/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntamayo- <ntamayo-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 15:19:12 by ntamayo-          #+#    #+#             */
/*   Updated: 2022/09/19 12:38:02 by ntamayo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**g_env;

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

int	main(int argc, char **argv, char **envp)
{
	char		*cmndline;
	t_parsing	*cts;

	cts = NULL;
	g_env = envp;
	while (1)
	{
		cmndline = readline("pinche_perro@minishell~ $ ");
		// Handle signals here.
		if (cmndline[0])
		{
			add_history(cmndline);
			if (!ft_strncmp(cmndline, "exit", 5))
				break ;
			cts = parse_line(cmndline);
			if (cts)
				print_table(cts);
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
