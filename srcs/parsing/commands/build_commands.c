# include "../../../includes/minishell.h"

int	get_infile(t_token *tokens)
{
	int	infile;

	infile = STDIN_FILENO;
	if (tokens->prev != NULL)
	{
		if (is_redirection(tokens->prev->token[0]))
		{
			if (tokens->prev->type == T_PIPE)
				printf("There's a pipe before this command\n");
			else if (tokens->prev->type == T_REDIR)
				printf("There's a redirection before this command\n");
			else if (tokens->prev->type == T_HEREDOC)
				infile = open_heredoc(tokens);
			//need to check if the delimiter is the whole token or if it
			//is possible to send a delimiter THEN a command
		}
	}
	return (infile);
}

int	get_outfile(t_token	*tokens)
{
	int	outfile;

	outfile = STDOUT_FILENO;
	if (tokens->next)
	{
		if (is_redirection(tokens->next->token[0]))
		{
			if (tokens->next->type == T_PIPE)
				printf("There is a pipe after this command\n");
			else if (tokens->next->type == T_REDIR)
				printf("There is a redirection after this command\n");
			else if (tokens->next->type == T_HEREDOC)
				printf("There's a heredoc after this command\n");
		}
	}
	return (outfile);
}

void	build_commands(void)
{
	t_token	*tokens;
	int		i;
	int		infile;
	int		outfile;

	i = 1;
	infile = STDIN_FILENO;
	outfile = STDOUT_FILENO;
	tokens = use_data()->token;
	if (!tokens->next)
		add_command(tokens->token, infile, outfile);
	else
	{
		while (tokens && tokens->next)
		{
			if (is_redirection(tokens->token[0]) && tokens->next)
				tokens = tokens->next;
			infile = get_infile(tokens);
			outfile = get_outfile(tokens);
			add_command(tokens->token, infile, outfile);
			if (tokens->next)
				tokens = tokens->next;
		}
	}
}
