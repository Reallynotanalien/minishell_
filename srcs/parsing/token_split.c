# include "../../includes/minishell.h"

int	is_redirection(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	return (NO);
}

void	*ft_memncpy(void *dest, const void *src, int start, int end)
{
	size_t	a;

	a = 0;
	if (!dest && !src)
		return (NULL);
	while (start <= end)
	{
		((char *)dest)[a] = ((char *)src)[start];
		start++;
		a++;
	}
	return (dest);
}

char	*ft_strndup(char *src, int start, int end)
{
	int		len;
	char	*copy;

	len = end - start + 1;
	copy = ft_calloc(sizeof(char), len + 1);
	if (copy == NULL)
		return (NULL);
	ft_memncpy(copy, src, start, end);
	return (copy);
}

int	split_tokens(void)
{
	char	*temp;
	char	*token;
	int		count;
	int		end;

	count = 0;
	temp = ft_strdup(use_data()->line);
	if (!temp)
		return (print_error(STRDUP_ERROR));
	while (temp[count] != '\0')
	{
		token = NULL;
		end = count;
		if (is_redirection(temp[count]))
		{
			//parsing redirection should check if there are 3 symbols next to one another
			if (parsing_redirection(use_data()->line, count) != ERROR)
			{
				if (temp[count] == temp[count + 1])
					end++;
				token = ft_strndup(temp, count, end);
				add_token(token);
				count = end++;
			}
		}
		free(token);
		count++;
	}
	free(temp);
	return (0);
}
