#ifndef EXEC_H
# define EXEC_H

/*INCLUDES*/
# include "minishell.h"

/*ERROR MESSAGES*/
# define FORK_ERROR "Error: fork did not work."
# define PIPE_ERROR "Error: pipe did not work."
# define PATH_ERROR "Error: path not found."
# define COMMAND_ERROR "Error: command not found."
# define ENV_ERROR "Error: PATH is not an environment variable."
# define OPEN_ERROR "Error: file could not be opened."

/*STRUCTS*/


/*FUNCTIONS*/

//exec.c
void	exec(t_shell *sh);

#endif