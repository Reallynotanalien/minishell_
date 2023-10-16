#ifndef PARSING_H
# define PARSING_H

/*INCLUDES*/

/*ERROR MESSAGES*/
# define STRDUP_ERROR "Could not duplicate string.\n"

/*STRUCTS*/

/*FUNCTIONS*/

//errors.c
void	parsing_error(char *error);
void	cleanup(void);
void	exit_program(void);

//parsing.c
int		main_parsing(int argc, char **argv, char **env);
void	parsing(void);
int		parsing_redirection(char *line, int index);
int		line_parsing(void);

//signals.c
void	signals(void);

//term_attributes.c
void	disable_ctrlc(void);
void	restore_attributes(void);

//token_split.c
int	split_tokens(void);

#endif