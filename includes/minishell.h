#ifndef MINISHELL_H
# define MINISHELL_H

/*INCLUDES*/
# include <stdio.h>
# include "libft/libft.h"
# include "./readline/history.h"
# include "./readline/readline.h"
# include "exec.h"
# include "parsing.h"
# include "builtins.h"
# include "printer.h"
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
//This will be the main static struct, to be modified as we go!
typedef struct data
{
	int	error_flag;
}				t_data;


/*FUNCTIONS*/

//init.c
void	init_data(t_data *data);

//utils.c
void	print_progress(int printer, char *message);
t_data	*use_data(void);


#endif