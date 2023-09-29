# include "../../includes/minishell.h"

void	parsing_error(char *error)
{
	printf("ERROR: %s\n", error);
	use_data()->error_flag = ERROR;
}

void	cleanup()
{
	rl_clear_history();
	free(use_data());
}

void	exit_program()
{
	cleanup();
	//printf to be deleted later on
	printf("Cleanup done!\n");
	exit(1);
}
