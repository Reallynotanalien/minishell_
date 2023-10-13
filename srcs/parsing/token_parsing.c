
#include "../../includes/minishell.h"

/*The below functions test the behavior of tokens surrounded by 
all symbols required to handle in the subject. 
Everything else is considered a string.
If an error should occur because of an invalid string, 
it will be handled by execve.*/

//No command on left, no command on right, double pipe
int	parsing_pipe(char *line, int index)
{
	if (index == 0 || line[index + 1] == '|'
		|| !ft_strncmp(&line[index], "| |", 3))
		return (print_error
			("minishell: syntax error near unexpected token '|'"));
	else if (!line[index + 1])
		return (print_error
			("minishell: syntax error near unexpected token 'newline'"));
	return (0);
}

// < missing input file (on right), redirection symbol on right
int	parsing_inredirect(char *line, int index)
{
	if (!line[index + 1])
		return (print_error
			("minishell: syntax error near unexpected token 'newline'"));
	else if ()
	
}

//>
int	parsing_outredirect(char *line, int index)
{

}

//<<
int	parsing_heredoc(char *line, int index)
{
}

//>>
int	parsing_appoutredirect(char *line, int index)
{

}

int next_isredirection(char *line, int index)
{
	if (ft_iswhitespace(line[index + 1] == 1))
		if (line[index + 2] == '<' || line[index + 2] == '>' || line[index + 2] == '|')
			return (1);
	else
		if (line[index + 1] == '<' || line[index + 1] == '>' || line[index + 1] == '|')
			return (1);
}
