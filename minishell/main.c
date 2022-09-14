#include "minishell.h"

t_task	*ft_parser(char *line)
{
	t_task	*cmds_array;
	char	**cmds;

	(void)line;

	cmds_array = malloc((3 + 1) * sizeof(t_task));

	cmds = malloc((2 + 1) * sizeof(char *));
	cmds[0] = ft_strdup("cat");
	cmds[1] = ft_strdup("main.c");
	cmds[2] = NULL;

	cmds_array[0].cmds = cmds;

	cmds = malloc((2 + 1) * sizeof(char *));
	cmds[0] = ft_strdup("grep");
	cmds[1] = ft_strdup("a");
	cmds[2] = NULL;

	cmds_array[1].cmds = cmds;

	cmds = malloc((2 + 1) * sizeof(char *));
	cmds[0] = ft_strdup("wc");
	cmds[1] = ft_strdup("-l");
	cmds[2] = NULL;

	cmds_array[2].cmds = cmds;

	cmds_array[3].cmds = NULL;

	return (cmds_array);
}

int	main(int argc, char **argv, char **envp)
{
	char *line;
	t_task *task;

	(void)argc;
	(void)argv;
	
	signal(SIGINT, INT_handler);
	signal(SIGQUIT, QUIT_handler);
	while (1)
	{
		line = readline("minishell: ");
		ft_putstr_fd(line, 1);
		ft_putstr_fd("\nstart\n", 1);
		if (!line)
		{
			ft_putstr_fd("Ctrl + D Pulsado\n", 1);
			exit(0);
		}
		task = ft_parser(line);
		ft_putstr_fd("fake cmd done\n", 1);
		add_history(line);
		ft_executor(task, envp);
		ft_putstr_fd("cmds executed\n", 1);
		free(line);
	}
	system("leaks minishell");
	return (0);
}
