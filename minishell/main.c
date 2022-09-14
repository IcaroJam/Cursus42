#include "libminishell.h"

void	ft_parser(char *line)
{
	char ***fake_task;

	fake_task = (char ***) malloc((25 + 1) * sizeof(char *));
	fake_task[0][0] = ft_strdup("NULL");
	fake_task[1][0] = ft_strdup("NULL");
	fake_task[2][0] = ft_strdup("echo");
	fake_task[2][1] = ft_strdup("-n");
	fake_task[2][2] = ft_strdup("prueba");
	fake_task[3][0] = ft_strdup("");
	return (fake_task);
}

int	main(int argc, char **argv, char **envp)
{
	char *line;
	char ***task;

	(void)argc;
	(void)argv;
	
	while (1)
	{
		line = readline("minishell: ");
		task = ft_parser(line);
		add_history(line);
		ft_execute(task, envp);
		free(line);
	}
	clear_history();
	system("leaks minishell");
	return (0);
}
