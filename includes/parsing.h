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
int		main_parsing(int argc, char **argv, char **env);
void	parsing(void);

//signals.c
void	signals(void);

//term_attributes.c
void	disable_ctrlc(void);
void	restore_attributes(void);

#endif