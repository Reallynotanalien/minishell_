#ifndef MINISHELL_H
# define MINISHELL_H

/*INCLUDES*/
# include "libft/libft.h"
# include "./readline/history.h"
# include "./readline/readline.h"
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
# define FORK_ERROR "Error: fork did not work."
# define PIPE_ERROR "Error: pipe did not work."
# define PATH_ERROR "Error: path not found."
# define COMMAND_ERROR "Error: command not found."
# define ENV_ERROR "Error: PATH is not an environment variable."
# define OPEN_ERROR "Error: file could not be opened."

/*STRUCTS*/


/*FUNCTIONS*/

/*----------builtins----------*/

/*----------exec----------*/
//exec.c
void	exec(void);

/*----------parsing----------*/
//parsing.c
void	parsing(char *line, t_dlist *tokens);
//signals.c
void	signals(void);


#endif