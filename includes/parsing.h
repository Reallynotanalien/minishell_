#ifndef PARSING_H
# define PARSING_H

/*INCLUDES*/
# include "minishell.h"

/*ERROR MESSAGES*/

/*STRUCTS*/

/*FUNCTIONS*/

//errors.c
void	parsing_error(t_shell *sh, char *error);
void	cleanup(t_shell *sh);
void	exit_program(t_shell *sh);

//init.c
void	init_struct(t_shell *sh);

//parsing.c
//void	parsing(char *line, t_dlist *tokens);
void	parsing(char *line, t_shell *sh);

//signals.c
void	signals(void);

#endif