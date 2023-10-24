# include "../../includes/minishell.h"

/*Returns yes if the character is a redirection character
(|, < or >).*/
int	is_redirection(char c)
{
	if (c == '|' || c == '<' || c == '>')
		return (YES);
	return (NO);
}

/*Returns yes if the character is a double quote.*/
int	is_double_quote(char c)
{
	if (c == '"')
		return (YES);
	return (NO);
}

/*Returns yes if the string contains a '$', meaning something has to be
substituted.*/
int	contains_substitution(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '$')
			return (YES);
		i++;
	}
	return (NO);
}
