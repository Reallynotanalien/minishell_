# include "../../includes/minishell.h"
# include "../../includes/parsing.h"

void	parsing(char *line, t_shell *sh)
{
	init_struct(sh);
	//This line below is just for testing. To be deleted later on.
	if (!line)
		parsing_error(sh, "There was an error!!");
}
