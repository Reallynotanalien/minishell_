#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	if (main_parsing(argc, argv, env) == ERROR)
		exit(1);
	signals();
	while (1)
	{
		use_data()->line = remove_spaces(readline("minishell$> "));
		if (!use_data()->line)
			return (ERROR);						//Probably not the right return value. (Syntax error " or allocation failed.)
		if (use_data()->line && *use_data()->line)
		{
			if (line_parsing() == ERROR)
				break ;
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
