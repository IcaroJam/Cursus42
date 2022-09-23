/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:06:32 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/23 13:31:18 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_export_var(char *var, char **env)
{
	(void)var;
	(void)env;
}

int	ft_export(t_parsing task, char **env)// si no hay "=" no asigna, si hay mas de uno da igual
{
	int count;

	count = 0;
	while (task.cmndtable[++count])
		if (ft_strchr(task.cmndtable[count], '=') && task.cmndtable[count][0] != '=')
			ft_export_var(task.cmndtable[count], env);
	return (0);
}

int	ft_unset(t_parsing task, char **env)
{
	(void)task;
	(void)env;
	return (0);
}

//void ft_builtins(t_parsing task, char **env, t_parsing *cts, char *cmndline)
int ft_builtins(t_parsing task, char **env)
{
	int exit_code;

	exit_code = 0;
	if (!ft_strncmp(task.cmndtable[0], "echo", 5))
	{
		ft_putstr_fd("Doing echo: \n", 1);
		exit_code = ms_echo(task);
	}
	else if (!ft_strncmp(task.cmndtable[0], "cd", 3))
	{
		ft_putstr_fd("Doing cd: \n", 1);
		exit_code = ms_cd((const char **)task.cmndtable);
	}
	else if (!ft_strncmp(task.cmndtable[0], "pwd", 4))
	{
		ft_putstr_fd("Doing pwd: \n", 1);
		exit_code = ms_pwd();
	}
	else if (!ft_strncmp(task.cmndtable[0], "export", 7))
	{
		ft_putstr_fd("Doing export: \n", 1);
		exit_code = ft_export(task, env);
	}
	else if (!ft_strncmp(task.cmndtable[0], "unset", 6))
	{
		ft_putstr_fd("Doing unset: \n", 1);
		exit_code = ft_unset(task, env);
	}
	else if (!ft_strncmp(task.cmndtable[0], "env", 4))
	{
		ft_putstr_fd("Doing env: \n", 1);
		exit_code = ms_env(env);
	}
	else if (!ft_strncmp(task.cmndtable[0], "exit", 5))
		//ms_exit(cts, cmndline);
		; //me van a sobrar argumentos en funciones para pasarle todo arreglar funciones
	return (exit_code);
}


int	ft_check_built(t_parsing task, char **env, t_process *process)
{
	int	built;
	int tmp_stdin;
	int tmp_stdout;

	ft_putstr_fd("checking built\n", 1);
	built = 1;
	if (!ft_strncmp(task.cmndtable[0], "echo", 5) || !ft_strncmp(task.cmndtable[0], "cd", 3)
			|| !ft_strncmp(task.cmndtable[0], "pwd", 4) || !ft_strncmp(task.cmndtable[0], "export", 7)
			|| !ft_strncmp(task.cmndtable[0], "unset", 6) || !ft_strncmp(task.cmndtable[0], "env", 4)
			|| !ft_strncmp(task.cmndtable[0], "exit", 5))
	{
		ft_putstr_fd("built command\n", 1);
		tmp_stdin = dup(0);
		tmp_stdout = dup(1);
		dup2(process->fd_in, 0);
		dup2(process->fd_out, 1);
		close(process->fd_in);
		close(process->fd_out);
		process->exit_code = ft_builtins(task, env);
		dup2(tmp_stdin, 0);
		dup2(tmp_stdout, 1);
	}
	else
		built = 0;
	return (built);
}
