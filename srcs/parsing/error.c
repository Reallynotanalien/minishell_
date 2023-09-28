# include "../../includes/minishell.h"

/*NOW WHENEVER WE EXIT THE PROGRAM WE SHOULD FREE THE MAIN STRUCT*/

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
	printf("Cleanup done!\n");
	exit(1);
}
