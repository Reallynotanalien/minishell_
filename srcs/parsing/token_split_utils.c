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
