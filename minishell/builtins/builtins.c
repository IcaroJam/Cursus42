/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phijano- <phijano-@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:06:32 by phijano-          #+#    #+#             */
/*   Updated: 2022/09/19 13:00:46 by phijano-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_export_var(char *var, char **env)
{
	(void)var;
	(void)env;
}

void	ft_echo(t_parsing task)//Arreglar para la expansion de variables si hace falta
{
	int count;

	if (task.cmndtable[1])
	{
		if(!ft_strncmp(task.cmndtable[1], "-n", 3))
		{
			count = 1;
			while(task.cmndtable[++count])
				ft_putstr_fd(task.cmndtable[count], 1);
		}
		else
		{
			count = 0;
			while (task.cmndtable[++count])
				ft_putstr_fd(task.cmndtable[count], 1);
			ft_putstr_fd("\n", 1);
		}
	}
	else 
		ft_putstr_fd("\n", 1);
}

void	ft_cd(t_parsing task)// Mirar lo del entorno
{

	if (task.cmndtable[1])
		chdir(task.cmndtable[1]);//Comprobar si cambia env o que hace, si no arreglar parecido al else
	else
		chdir(getenv("HOME"));
}


void	ft_pwd()
{
	char *pwd;
	pwd = getenv("PWD");
	ft_putstr_fd(pwd, 1);
	ft_putstr_fd("\n", 1);
}

/*
void	ft_pwd(char **env)
{
	char *pwd;
	int count;

	count = -1;
	while (env[++count])
	{
		if (ft_strncmp(env[count], "PWD", 3))
		{
			pwd = ft_substr(env[count], 3, ft_strlen(env[count]));
			put_str_fd(pwd, 1);
			free (pwd);
			break;	
		}
	}
}
*/


void	ft_export(t_parsing task, char **env)// si no hay "=" no asigna, si hay mas de uno da igual
{
	int count;

	count = 0;
	while (task.cmndtable[++count])
		if (ft_strchr(task.cmndtable[count], '=') && task.cmndtable[count][0] != '=')
			ft_export_var(task.cmndtable[count], env);

}

void	ft_unset(t_parsing task, char **env)
{
	(void)task;
	(void)env;

}

void	ft_env(char **env)//puede que haga falta los \n
{
	int count;

	count = -1;
	while(env[++count])
		ft_putstr_fd(env[count], 1);

}
/*
void	ft_exit(t_task *task) //Arreglar para todo lo que tengamos que liberar
{
	(void)task;
	//ft_free(task); //hacer funcion para liberar
	exit(0);
}*/

int	ft_check_built(t_parsing task, char **env)
{
	int	built;

	ft_putstr_fd("checking built\n", 1);
	built = 1;
	if (!ft_strncmp(task.cmndtable[0], "echo", 5))// no se si vendran con ruta
	{
		ft_putstr_fd("Doing echo: \n", 1);
		ft_echo(task);
	}
	else if (!ft_strncmp(task.cmndtable[0], "cd", 3))// no se si vendran con ruta
	{
		ft_putstr_fd("Doing cd: \n", 1);
		ft_cd(task);
	}
	else if (!ft_strncmp(task.cmndtable[0], "pwd", 4))// no se si vendran con ruta
	{
		ft_putstr_fd("Doing pwd: \n", 1);
		ft_pwd();
	}
	else if (!ft_strncmp(task.cmndtable[0], "export", 7))// no se si vendran con ruta
	{
		ft_putstr_fd("Doing export: \n", 1);
		ft_export(task, env);
	}
	else if (!ft_strncmp(task.cmndtable[0], "unset", 5))// no se si vendran con ruta
	{
		ft_putstr_fd("Doing unset: \n", 1);
		ft_unset(task, env);
	}
	else if (!ft_strncmp(task.cmndtable[0], "env", 4))// no se si vendran con ruta
	{
		ft_putstr_fd("Doing env: \n", 1);
		ft_env(env);
	}
	else if (!ft_strncmp(task.cmndtable[0], "exit", 5))// no se si vendran con ruta
		//ft_exit(task); //tenemos que pasarle todo lo que haya que liberar
		;
	else
		built = 0;
	return (built);
}
