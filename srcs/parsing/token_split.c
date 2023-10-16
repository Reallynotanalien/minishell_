# include "../../includes/minishell.h"

int	split_tokens(void)
{
	char	*temp;

	temp = ft_strdup(use_data()->line);
	if (!temp)
		return (STRDUP_ERROR, ERROR);
	free(temp);
	return (0);
}