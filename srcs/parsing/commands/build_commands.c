# include "../../../includes/minishell.h"

t_token	*command_loop(t_token *tokens)
{
	while (tokens)
	{
		if (tokens->type == T_PIPE)
			break ;
		else if (tokens->type == T_HEREDOC)
			use_data()->infile = open_heredoc(tokens);
		else if (tokens->type == T_INFILE)
			printf("infile = open_infile();\n");
		else if (tokens->type == T_OUTFILE || tokens->type == T_APPEND)
			printf("outfile = open_outfile();\n");
		else if (tokens->type == T_STR)
			printf("add the str to command\n");
		if (tokens->next)
			tokens = tokens->next;
		else
			break ;
	}
	return (tokens);
}

void	build_commands(void)
{
	t_token	*tokens;
	int		i;

	i = 1;
	tokens = use_data()->token;
	while (tokens)
	{
		use_data()->infile = STDIN_FILENO;
		use_data()->outfile = STDOUT_FILENO;
		tokens = command_loop(tokens);
		if (tokens->type == T_PIPE)
			printf("Do pipe thing\n");
		add_command("tokens->token hello world", use_data()->infile, use_data()->outfile);
		if (tokens->next)
			tokens = tokens->next;
		else
			break ;
	}
}
