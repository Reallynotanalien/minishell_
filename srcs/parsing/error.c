# include "../../includes/minishell.h"

/*If an error is found in the parsing, an error message gets
printed and the error flag gets turned on. The parsing can then 
continue and print as many error messages as it needs without exiting
the program; the flag will get catched at the moment of the execution.*/
void	parsing_error(char *error)
{
	printf("ERROR: %s\n", error);
	use_data()->error_flag = ERROR;
}

/*Clears the readline history and frees the data struct.*/
void	cleanup(void)
{
	rl_clear_history();
	free(use_data());
}

/*Gracefully exits the program by cleaning up all necessary data
before printing an exit message and exiting.*/
void	exit_program(void)
{
	cleanup();
	//printf to be deleted later on
	printf("Cleanup done!\n");
	exit(1);
}
