#ifndef MINISHELL_H
# define MINISHELL_H

/*INCLUDES*/
# include "libft/libft.h"
# include "./readline/history.h"
# include "./readline/readline.h"
# include "builtins.h"
# include "exec.h"
# include "parsing.h"
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/signal.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <dirent.h>
# include <termios.h>
# include <curses.h>
# include <term.h>

/*VARIABLES*/
# define ERROR 1
# define YES 0
# define NO 1

/*ERROR MESSAGES*/

/*STRUCTS*/


/*FUNCTIONS*/

/*----------builtins----------*/

/*----------parsing----------*/
//parsing.c
void	parsing(char *line, t_dlist *tokens);
//signals.c
void	signals(void);


#endif