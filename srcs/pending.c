
#include "../includes/minishell.h"
//intended to avoid conflicts (to be moved later)



int	len_before_whitespace(char *str)
{
	int	i;

	i = 0;
	while (str[i] && !ft_iswhitespace(str[i]))
		i++;
	return (i);
}

/*
Substitutions : $?, $ENV, "", ''(erase ' ' and "" once $ have been dealt with, if not quoted.)
getenv to retrieve variable (in the form of a str).
If it does not exist, handle it as null
Considers a variable name is anything between $ and
the end of the line OR any whitespace
1 : Create an array of arrays to contain tokens (between variables VS variables) (1 : count number of arrays and allocates, 2 : places tokens (2.5 subsitute))
When placing a "variable name" in a token, substitute it. Also handle quotes
2 : count the tokens' total lenght to allocate 'new_token'. Then free the arrays
3 : ft_strjoin with all tokens, freeing them as it goes
(except for variable tokens, or allocate them manually)
4 : free token argument*/


/*	1 : create array of arrays
		a : find how many tokens there will be (when finding a '$', increase nb_tokens. advance i to end of token name. If i is still valid, and isn't $ or "$, increase nb_tokens)
		b : place tokens (between variable names, variable names (from $ to end of line or whitespace or quotes))
	2 : change $
	3 : erase unused ' and "
	4 : reconstruct new_token	*/
char	*substitute_variable(char *token)
{
	int	i;
	int	nb_tokens;

	i = -1;
	nb_tokens = 0;
	if (token[0] != '$')
		nb_tokens++;
	while (token[++i])
	{
		if (token[i] == '$' && !single_quoted(token, i))
		{
			nb_tokens++;
			while (token[i] && token[i] != '\'' && token[i] != '\"'
				&& token[i] != '$' && !ft_iswhitespace(token[i]))
				i++;
		}
		if (token[i] && token[i] != '$'
			&& (token [i + 1] && token[i] == '\"' && token[i + 1] == '$'))
			nb_tokens++;
	}
}


//This considers "str" was allocated (it frees it).
char	*ft_strtrim_whitespaces(char *str)
{
	int	i_start;
	int	i_end;

	i_start = 0;
	while (str[i_start] && ft_iswhitespace(str[i_start]))
		i_start++;
	i_end = ft_strlen(str) - 1;
	while (str[i_end] && ft_iswhitespace(str[i_end]))
		i_end--;
	free (str);
	return (ft_substr(str, i_start, i_end - i_start + 1));
}
