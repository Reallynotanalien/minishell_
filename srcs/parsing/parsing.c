# include "../../includes/minishell.h"

int	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (printf(ARGC_ERROR), ERROR);
	use_data()->new_env = env;
	if (!use_data()->new_env)
		return (printf(ENV_ERROR), ERROR);
	if (!argv)
		return (printf(ARGV_ERROR), ERROR);
	return (0);
}

int	line_parsing(void)
{
	//1- Look if all the quotes are closed if not return ERROR

	//2- Cut the line into tokens
	//3- Iterate through each token to make sure they are valid
	//and add them to the command struct
	return (0);
}
