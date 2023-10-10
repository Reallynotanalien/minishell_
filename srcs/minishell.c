#include "../includes/minishell.h"
#include "../includes/parsing.h"
#include "../includes/exec.h"

int	main(void)
{
	//t_dlist	*tokens;
	char	*line;
	
	//tokens = malloc(sizeof(t_dlist));
	signals();
	//mini parsing
	while (1)
	{
		line = readline("minishell$> ");
		if (line && *line)
		{
			parsing(line);
			if (use_data()->error_flag != ERROR)
				exec();
			add_history(line);
			//free tokens
		}
		if (line == NULL)
			exit_program();
		free(line);
	}
	cleanup();
	return (0);
}
