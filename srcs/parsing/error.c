# include "../../includes/minishell.h"

void	parsing_error(t_shell *sh, char *error)
{
	printf("ERROR: %s\n", error);
	sh->error_flag = ERROR;
}

void	cleanup(t_shell *sh)
{
	rl_clear_history();
	free(sh);
}

void	exit_program(t_shell *sh)
{
	cleanup(sh);
	//printf to be deleted later on
	printf("Cleanup done!\n");
	exit(1);
}
