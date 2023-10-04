# include "../../includes/minishell.h"

void	main_parsing(int argc, char **argv, char **env)
{
	if (!env)
		printf("No env wtfff\n");
	if (!argc)
		printf("No argc\n");
	if (!argv)
		printf("No argv\n");
}

void	parsing(void)
{
	//This line below is just for testing. To be deleted later on.
	if (!use_data()->line)
		parsing_error("There was an error!!");
}
