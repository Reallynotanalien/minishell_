#ifndef PARSING_H
# define PARSING_H

/*INCLUDES*/

/*ERROR MESSAGES*/

/*STRUCTS*/

/*FUNCTIONS*/

//errors.c
void	parsing_error(t_shell *sh, char *error);

//parsing.c
//void	parsing(char *line, t_dlist *tokens);
void	parsing(char *line, t_shell *sh);

//signals.c
void	signals(void);

#endif