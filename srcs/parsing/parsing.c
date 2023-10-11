# include "../../includes/minishell.h"

int	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (printf(ARGC_ERROR), 0);
	use_data()->new_env = env;
	if (!use_data()->new_env)
		return (printf("ENV ERROR\n"), 0);
	if (!argv)
		return (printf("No argv\n"), 0);
	return (1);
}

void	parsing(void)
{
	//This line below is just for testing. To be deleted later on.
	if (!use_data()->line)
		return (parsing_error("There should be a line\n"));
}
