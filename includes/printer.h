#ifndef PRINTER_H
# define PRINTER_H

/*INCLUDES*/


/*VARIABLES*/
# ifndef PRINTER
#  define PRINTER NO
# endif

/*ERROR MESSAGES*/
# define SIGNALS_OK "1: You have successfuly gone through the signals functions."
# define GLOBAL_PARSING_OK "2: You have successfuly gone through the global parsing."
# define READLINE_OK "3: The line have sucessfuly been read by readline."
# define PARSING_OK "4: You have successfuly gone through the parsing."
# define EXEC_OK "5: You have successfuly gone through the exec."
# define HISTORY_OK "6: You have successfuly added the line to history."
# define FREE_TOKENS_OK "7: You have successfuly freed the tokens."
# define FREE_LINE_OK "8: You have successfuly freed the line."
# define LOOP_ENDED "9: Seems like something broke your while() loop!"
# define CLEAR_HISTORY_OK "10: You have successfuly cleared the history."

/*STRUCTS*/


/*FUNCTIONS*/

//utils.c
void	print_progress(int printer, char *message);


#endif