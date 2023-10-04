# include "../../includes/minishell.h"

void	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
	{
		printf("No argument should be sent appart from the program's name\n");
		exit(1);
	}
	use_data()->new_env = env;
	if (!argv)
		printf("No argv\n");
}

void	parsing(void)
{
	//This line below is just for testing. To be deleted later on.
	if (!use_data()->line)
		parsing_error("There was an error!!");
}
