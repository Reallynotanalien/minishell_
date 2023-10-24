# include "../../includes/minishell.h"

void	get_infile(t_token *tokens)
{
	if (tokens->prev != NULL)
	{
		if (is_redirection(tokens->prev->token[0]))
		{
			if (tokens->prev->type == T_PIPE)
				printf("There's a pipe before this command\n");
			else if (tokens->prev->type == T_REDIR)
				printf("There's a redirection before this command\n");
			else if (tokens->prev->type == T_HEREDOC)
				printf("There's a heredoc before this command \n");
		}
	}
	else
		use_data()->cmd->infile = STDIN_FILENO;
}

void	get_outfile(t_token	*tokens)
{
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
	else
		use_data()->cmd->outfile = STDOUT_FILENO;
}

void	build_commands(void)
{
	t_token	*tokens;
	int		i;

	i = 1;
	tokens = use_data()->token;
	if (!tokens->next)
		add_command(tokens->token);
	else
	{
		while (tokens && tokens->next)
		{
			if (is_redirection(tokens->token[0]) && tokens->next)
				tokens = tokens->next;
			add_command(tokens->token);
			get_infile(tokens);
			get_outfile(tokens);
			if (tokens->next)
				tokens = tokens->next;
		}
	}
}
