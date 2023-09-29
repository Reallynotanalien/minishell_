#ifndef PARSING_H
# define PARSING_H

/*INCLUDES*/
# include "minishell.h"

/*ERROR MESSAGES*/

/*STRUCTS*/

/*FUNCTIONS*/

//errors.c
void	parsing_error(char *error);
void	cleanup();
void	exit_program();

//init.c
void	init_data(t_data *data);

//parsing.c
//void	parsing(char *line, t_dlist *tokens);
void	parsing(char *line);

//signals.c
void	signals(void);

#endif