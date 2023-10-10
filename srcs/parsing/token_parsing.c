
#include "../../includes/minishell.h"

void	parsing_pipe(char *line, int index)
{
	if (!line[index - 1] || !line[index + 1] || line[index + 1] == '|' 
		|| !ft_strncmp(&line[index], "| |", 3))
		exit_error ("minishell: syntax error near unexpected token '|'");
}

//<
void	parsing_inredirect(char *line, int index)
{
	
}

//>
void	parsing_outredirect(char *line, int index)
{

}

//<<
void	parsing_heredoc(char *line, int index)
{
}

//>>
void	parsing_appoutredirect(char *line, int index)
{

}