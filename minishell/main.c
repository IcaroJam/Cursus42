#include "minishell.h"
#include "parser/msparser.h"

int	main(void)
{
	char		*cmndline;
	t_parsing	cts;

	while (1) {
		cmndline = readline("pinche_perro@minishell~ $ ");
		add_history(cmndline);
		if (!ft_strncmp(cmndline, "EXIT", 5))
			break ;
		cts = parse_line(cmndline);
		//if (!cts)
		free(cmndline);
	}
	//
	system("leaks minishell");
	//
	return (0);
}
