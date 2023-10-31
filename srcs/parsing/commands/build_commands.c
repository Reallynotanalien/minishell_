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
		else if (tokens->type == T_INFILE)
			printf("open_infile()\n");
		else if (tokens->type == T_OUTFILE || tokens->type == T_APPEND)
			printf("open_outfile()\n");
		else
			add_command(tokens->token, infile, outfile);
	}
	else
	{
		while (tokens)
		{
			infile = STDIN_FILENO;
			outfile = STDOUT_FILENO;
			while (tokens)
			{
				if (tokens->type == T_PIPE)
					break ;
				else if (tokens->type == T_HEREDOC)
					infile = open_heredoc(tokens);
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
			if (tokens->type == T_PIPE)
				printf("Do pipe thing\n");
			add_command("tokens->token", infile, outfile);
			if (tokens->next)
				tokens = tokens->next;
			else
				break ;
		}
	}
}
