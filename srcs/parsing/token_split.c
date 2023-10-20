# include "../../includes/minishell.h"

int	is_redirection(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	return (NO);
}

int	is_double_quote(char c)
{
	if (c == '"')
		return (YES);
	return (NO);
}

int	iterate_until_quotes_are_closed(char *line, int end)
{
	while (line[end + 1] && !is_double_quote(line[end + 1]))
		end++;
	if (!ft_iswhitespace(line[end + 1]))
		return (end);
	return (end + 1);
}

int	iterate_until_redirection(char *line, int end)
{
	while (line[end] && line[end + 1]
		&& !is_redirection(line[end + 1]))
		//&& !is_double_quote(line[end]))
	{
		//if (is_redirection(line[end]))
			//return (end);
		if (line[end + 1] == '"')
			end = iterate_until_quotes_are_closed(line, end + 1);
		end++;
	}
	printf("I have iterated through redirections\n");
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
	while (line[count] && line[count + 1])
	{
		token = NULL;
		end = count;
		if (!is_redirection(line[count]))
			end = iterate_until_redirection(line, end);
		else
		{
			if (parsing_redirection(line, count) != ERROR)
			{
				if (line[count] == line[count + 1])
					end++;
			}
			else
				return ;
		}
		//trouver comment envoyer tous les whitespaces à strtrim
		token = ft_strtrim(ft_substr(line, count, (end - count + 1)), " ");
		add_token(token);
		count = end;
		free(token);
		count++;
	}
	free(line);
}
