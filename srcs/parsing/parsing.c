# include "../../includes/minishell.h"

/*Checks if the minishell args are valid and makes a copy
of the env variable to be used later.*/
int	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (print_error(ARGC_ERROR));
	use_data()->new_env = env;
	if (!use_data()->new_env)
		return (print_error(ENV_ERROR));
	if (!argv)
		return (print_error(ARGV_ERROR));
	return (0);
}

/*First checks if all the quotes are closed, if not, returns ERROR
and sets the error flag to ERROR. Then, splits the line into tokens.*/
void	line_parsing(void)
{
	if (parse_quotes(use_data()->line) == ERROR)
		return ;
	split_tokens();
	view_list();
	//3- Iterate through each token to make sure they are valid
	//and add them to the command struct
	free_tokens_if_not_empty();
}
