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
# define ARGC_ERROR "No argument should be sent appart from the program's name\n"

/*STRUCTS*/
//This will be the main static struct, to be modified as we go!
typedef struct data
{
	char			**new_env;
	char			*line;
	int				error_flag;
	struct termios	old_attributes;
	struct termios	new_attributes;
}				t_data;

/*FUNCTIONS*/

//init.c
void	init_data(t_data *data);

//utils.c
t_data	*use_data(void);

#endif