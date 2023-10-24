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
and sets the error flag to ERROR. Then, splits the line into tokens.
Those tokens are then used to create a command list, in which each 
command will be associated with the right input and output file for
easy execution.*/
void	line_parsing(void)
{
	if (parse_quotes(use_data()->line) == ERROR)
		return ;
	if (remove_spaces(use_data()->line) == ERROR)
		return ;
	if (split_tokens() == ERROR)
		return (free_tokens_if_not_empty());
	view_list();
	printf("build_commands()\n");
	printf("view_commands()\n");
	free_tokens_if_not_empty();
}
