#include "../includes/minishell.h"

int	main(void)
{
	signals();
	while (1)
	{
		use_data()->line = readline("minishell$> ");
		if (use_data()->line && *use_data()->line)
		{
			parsing();
			if (use_data()->error_flag != ERROR)
				exec();
			add_history(use_data()->line);
			//free tokens
		}
		if (use_data()->line == NULL)
			exit_program();
		free(use_data()->line);
	}
	cleanup();
	return (0);
}
