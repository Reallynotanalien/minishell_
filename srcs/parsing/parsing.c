# include "../../includes/minishell.h"

int	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (printf(ARGC_ERROR), 0);
	use_data()->new_env = env;
	if (!use_data()->new_env)
		return (printf(ENV_ERROR), 0);
	if (!argv)
		return (printf(ARGV_ERROR), 0);
	return (1);
}

void	parsing(void)
{
	//Cut the line into tokens
	//Iterate through each token to make sure they are valid
	//and add them to the command struct
}
