#ifndef PARSING_H
# define PARSING_H

/*INCLUDES*/

/*ERROR MESSAGES*/

/*STRUCTS*/

/*FUNCTIONS*/

//errors.c
void	parsing_error(char *error);
void	cleanup(void);
void	exit_program(void);

//parsing.c
//void	parsing(char *line, t_dlist *tokens);
void	parsing(void);

//signals.c
void	signals(void);

//term_attributes.c
void	disable_ctrlc(void);
void	restore_attributes(void);

#endif