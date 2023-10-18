#ifndef PARSING_H
# define PARSING_H

/*INCLUDES*/

/*ERROR MESSAGES*/
# define STRDUP_ERROR "Could not duplicate string.\n"
# define QUOTES_ERROR "found unclosed quotation marks"

/*STRUCTS*/

/*FUNCTIONS*/

//errors.c
int		parsing_error(char *error);
void	cleanup(void);
void	exit_program(void);
int		print_error(char *message);

//line_parsing.c
int		parse_quotes(char *str);
char	*remove_spaces(char *str);

//parsing.c
char	*remove_spaces(char *str);
int		main_parsing(int argc, char **argv, char **env);
void	parsing(void);
int		parsing_redirection(char *line, int index);
void	line_parsing(void);

//signals.c
void	signals(void);

//term_attributes.c
void	disable_ctrlc(void);
void	restore_attributes(void);

//token_split.c
void	split_tokens(void);

#endif