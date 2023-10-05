# include "../../includes/minishell.h"

void	parsing_error(char *error)
{
	printf("ERROR: %s\n", error);
	use_data()->error_flag = ERROR;
}

void	clean_data(void)
{
	if (use_data())
		free (use_data());
}

void	cleanup(void)
{
	rl_clear_history();
	clean_data();
}

void	exit_program(void)
{
	cleanup();
	//printf to be deleted later on
	printf("Cleanup done!\n");
	exit(1);
}
