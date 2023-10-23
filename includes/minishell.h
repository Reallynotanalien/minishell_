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
# define YES 1
# define NO 0
# define T_STR 1
# define T_SUBST 2
# define T_PIPE 3
# define T_REDIR 4
# define T_HEREDOC 5

/*ERROR MESSAGES*/
# define ARGC_ERROR "No argument should be sent appart from the program's name"
# define ENV_ERROR "The environment could not be copied"
# define ARGV_ERROR "There is no argv"

/*STRUCTS*/

typedef struct s_command
{
	int					infile;
	int					outfile;
	char				*cmd;
	char				*args;
	struct s_command	*next;
}					t_command;

//This struct represents the tokens used for each readline return.
//They are seperated in different types defined in VARIABLES.
typedef struct s_token
{
	char			*token;
	int				type;
	struct s_token	*next;
}	t_token;

//This will be the main static struct, to be modified as we go!
typedef struct s_data
{
	struct s_token		*token;
	struct s_command	*cmd;
	int					error_flag;
	int					quote_flag;
	char				**new_env;
	char				*line;
	char				*line_cpy;
	struct termios		old_attributes;
	struct termios		new_attributes;
}				t_data;

//FUNCTIONS

//init.c
void	init_data(t_data *data);

//utils.c
int		double_quoted(char *str, int index);
int		single_quoted(char *str, int index);
t_data	*use_data(void);

//linked_list.c
t_token	*add_token(char *token);
void	free_tokens_if_not_empty(void);
t_token	*newlst(char *token, int type);
void	addlst(t_token *lst, char *token, int type);
void	view_list(void);

//command_list.c
t_command	*create_command(void);
t_command	*add_command(char *command);
void		free_commands_if_not_empty(void);
void		view_commands(void);

#endif