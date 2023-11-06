
#include "../../includes/minishell.h"
#include "../../includes/parsing.h"

// >
// int	token_redirout(t_token *token, t_command *cmd)
// {
// 	int	fd;

// 	if (access(token, F_OK) == 0 
// 		|| access(ft_tolower(token), F_OK == 0))
// 	{
// 		if (access (token, W_OK) == 0 || access (ft_tolower(token), W_OK) == 0)
// 			fd = open(token, O_TRUNC | O_WRONLY);
// 		else
// 			return (-1);
// 	}
// 	else
// 		fd = open(token, O_CREAT | O_TRUNC | O_WRONLY, 0644);
// 	if (cmd->outfile != STDOUT_FILENO)
// 		close(cmd->outfile);
// 	cmd->outfile = fd;
// 	return (0);
// }

// //<
// int	token_redirin(t_token *token, t_command *cmd)
// {
// 	int	fd;

// 	if (access(token, O_RDONLY) == 0 || access(ft_tolower(token), O_RDONLY == 0))
	
// 	if (cmd->infile != STDOUT_FILENO)
// 		close(cmd->infile);
// 	cmd->infile = fd;
// }

// int	token_pipe(t_token *token)
// {

// }

// //>>
// int	token_redirappend(t_token *token)
// {

// }
