
#include "../../includes/minishell.h"
#include "../../includes/parsing.h"

//v check if it exists; if not, print error. Otherwise, check for rights; if invalid, print error.
//If all is valid, add the file in the right field of "cmd". (will be redirected at exec)
// >
int	token_redirout(t_token *token, t_command *cmd)
{
	int		fd;
	char	*token_lower;

	token_lower = ft_strlower(token->token);
	if (access(token->token, F_OK) == 0 
		|| access(token_lower, F_OK) == 0)
	{
		if (access (token->token, W_OK) == 0
			|| access ((token_lower), W_OK) == 0)
			fd = open(token, O_TRUNC | O_WRONLY);
		else
			return (free(token_lower), -1);
	}
	else
		fd = open(token->token, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (cmd->outfile != STDOUT_FILENO)
		close(cmd->outfile);
	cmd->outfile = fd;
	return (free(token_lower), 0);
}

//<
int	token_redirin(t_token *token, t_command *cmd)
{
	int		fd;
	char	*token_lower;

	token_lower = ft_strlower(token->token);
	if (access(token->token, O_WRONLY == 0))
		open(token->token, O_WRONLY);
	else if (access(token_lower, O_WRONLY == 0))
		open(token_lower, O_WRONLY);
	else
		return (free(token_lower), ERROR);
	if (cmd->infile != STDOUT_FILENO)
		close(cmd->infile);
	cmd->infile = fd;
	return (free(token_lower), EXIT_SUCCESS);
}
