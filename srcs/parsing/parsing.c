# include "../../includes/minishell.h"

int	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (printf(ARGC_ERROR), 0);
	use_data()->new_env = env;
	if (!argv)
		printf("No argv\n");
	return (1);
}

void	parsing(void)
{
	//This line below is just for testing. To be deleted later on.
	if (!use_data()->line)
		parsing_error("There was an error!!");
}
