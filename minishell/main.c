#include "minishell.h"

int	main(void)
{
	char	*cmndline;
	char	***cmndtable;

	while (1) {
		cmndline = readline("pinche_perro@minishell~ $ ");
		add_history(cmndline);
		cmndtable = parse_line(cmndline);
		free(cmndline);
		if (!ft_strncmp(cmndline, "EXIT", 5))
			break ;
	}
	return (0);
}
