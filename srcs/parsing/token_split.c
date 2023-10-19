# include "../../includes/minishell.h"

int	is_redirection(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	return (NO);
}

int	iterate_until_redirection(char *line, int end)
{
	while (line[end] && line[end + 1]
		&& !is_redirection(line[end + 1]))
		end++;
	return (end);
}

void	check_type(char *token)
{
	if (is_redirection(token[0]))
	{
		if (token[0] == '|')
			use_data()->token->type = T_PIPE;
		else if (token[0] == '<')
		{
			if (token[1] != '\0')
				use_data()->token->type = T_HEREDOC;
			else
				use_data()->token->type = T_REDIR;
		}
		else if (token[0] == '>')
		{
			use_data()->token->type = T_REDIR;
		}
	}
	else
	{
		printf("check_if_file()\n");
		printf("check_if_substitution()\n");
	}
}

void	split_tokens(void)
{
	char	*token;
	char	*line;
	int		count;
	int		end;

	count = 0;
	line = ft_strdup(use_data()->line);
	while (line[count] != '\0' && line[count + 1] != '\0')
	{
		token = NULL;
		end = count;
		if (!is_redirection(line[count]))
			end = iterate_until_redirection(line, end);
		else
		{
			if (parsing_redirection(line, count) != ERROR)
				if (line[count] == line[count + 1])
					end++;
		}
		token = ft_strtrim(ft_strdup_part(line, count, end), " ");
		add_token(token);
		printf("check_type(token)\n");
		count = end++;
		free(token);
		count++;
	}
	free(line);
}
