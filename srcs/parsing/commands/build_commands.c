# include "../../../includes/minishell.h"

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
	{
		if (tokens->type == T_HEREDOC)
			open_heredoc(tokens);
		else
			add_command(tokens->token, infile, outfile);
	}
	else
	{
		while (tokens)
		{
			if (tokens->type == T_HEREDOC)
				open_heredoc(tokens);
			add_command(tokens->token, infile, outfile);
			if (tokens->next)
				tokens = tokens->next;
		}
	}
}
