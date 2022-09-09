#include "minishell.h"
#include "parser/msparser.h"

int	main(void)
{
	char		*cmndline;
	//t_parsing	cts;

	while (1) {
		cmndline = readline("pinche_perro@minishell~ $ ");
		add_history(cmndline);
	//	cts = parse_line(cmndline);
		tokenize_line(cmndline);
		free(cmndline);
		if (!ft_strncmp(cmndline, "EXIT", 5))
			break ;
	}
	return (0);
}
