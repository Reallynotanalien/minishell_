# include "../../includes/minishell.h"

void	get_infile(t_token *tokens)
{
	if (lstget_prev(tokens, ))
		if (is_redirection(tokens->token[0]))
		{

		}
	else
		use_data()->cmd->infile = STDIN_FILENO;
}

void	get_outfile(t_token	*tokens)
{
	if (tokens->next)
		if (is_redirection(tokens->token[0]))
		{
			if (tokens->token[0] == '<')
				if (tokens->token[1] != '\0')
					//open outfile and cmd->outfile becomes this
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
	while (tokens)
	{
		if (is_redirection(tokens->token[0]))
			tokens = tokens->next;
		add_command(tokens->token);
		get_infile(tokens);
		get_outfile(tokens);
		if (tokens->next)
			tokens = tokens->next;
	}
}
