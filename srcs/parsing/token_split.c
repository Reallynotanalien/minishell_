# include "../../includes/minishell.h"

int	is_redirection(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	return (NO);
}

void	split_tokens(void)
{
	char	*token;
	int		count;
	int		end;

	count = 0;
	while (use_data()->line[count] != '\0'
		&& use_data()->line[count + 1] != '\0')
	{
		token = NULL;
		end = count;
		if (!is_redirection(use_data()->line[count]))
			while (use_data()->line[end]
				&& !is_redirection(use_data()->line[end + 1]))
				end++;
		else
		{
			//parsing redirection should check if there are 3 symbols next to one another
			if (parsing_redirection(use_data()->line, count) != ERROR)
				if (use_data()->line[count] == use_data()->line[count + 1])
					end++;
		}
		token = ft_strtrim(ft_strdup_part(use_data()->line, count, end), " ");
		add_token(token);
		count = end++;
		free(token);
		count++;
	}
}
