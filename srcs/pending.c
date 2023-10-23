
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

int	count_nbblocks(char *token)

int	count_nbblocks(char *token)
{
	int	i;
	int	nb_blocks;
	int	flag_var;
	int	nb_blocks;
	int	flag_var;

	i = -1;
	if (token[0] == '$')
		nb_blocks = 0;
	else
		nb_blocks = 1;
	flag_var = 0;
	if (token[0] == '$')
		nb_blocks = 0;
	else
		nb_blocks = 1;
	flag_var = 0;
	while (token[++i])
	{
		if (token[i] == '$' && !single_quoted(token, i) && token[i + 1])
		if (token[i] == '$' && !single_quoted(token, i) && token[i + 1])
		{
			nb_blocks++;
			flag_var = 1;
		}
		if ((ft_iswhitespace(token[i]) || token[i] == '\"' || token[i] == '\'')
			&& flag_var == 1)
		{
			nb_blocks++;
			flag_var = 0;
		}
	}
	return (nb_blocks);
}

char	*substitute_block(char *token, int index)
{
	int		i;
	char	*new_block;
	char	*var_name;

	i = index;
	if (token[index + 1] == '?')
		function_exstat();
	while (!ft_iswhitespace(token[i]) && token[i] != '\"' && token[i] != '\'')
		i++;
	var_name = ft_substr(token, index + 1, i - index);
	new_block = ft_calloc(ft_strlen(getenv(var_name)), sizeof(char));
	new_block = getenv(var_name);
}

int	create_blocks(char *token, char **blocks)
{
	int	i;
	int	i_block;

	i = 0;
	while (token[i])
	{
		while (token[i]
			&& !(token[i] == '$' && !single_quoted(token, i) && token[i + 1]))
			blocks[i][i_block] = token[i++];
		if (token[i])
		{
			blocks[i_block] = substitute_block(token, i);
			i += ft_strlen(blocks[i_block++]);
		}
	}
}

char	*substitute_variable(char *token)
{
	int		nb_blocks;
	char	**blocks;
	char	*new_token;

	nb_blocks = count_nbblocks(token);
	blocks = ft_calloc(nb_blocks, sizeof(char *));
	create_blocks(token, blocks);
// 	new_token = create_newtoken(blocks);

	// int		i;
	// int		nb_blocks;
	// char	**blocks;

	// i = 0;
	// nb_tokens = 0;
	// if (token[0] != '$')
	// 	nb_tokens++;
	// while (token[i])
	// {
	// 	if (token[i] == '$' && !single_quoted(token, i))
	// 	{
	// 		nb_tokens++;
	// 		while (token[i] && token[i] != '\'' && token[i] != '\"'
	// 			&& token[i] != '$' && !ft_iswhitespace(token[i]))
	// 			i++;
	// 	}
	// 	if (token[i] && token[i] != '$'
	// 		&& (token [i + 1] && token[i] == '\"' && token[i + 1] == '$'))
	// 		nb_tokens++;
	// 	i++;
	// }
	// var_division = ft_calloc(nb_tokens, sizeof(char *));

}
			nb_blocks++;
			flag_var = 1;
		}
		if ((ft_iswhitespace(token[i]) || token[i] == '\"' || token[i] == '\'')
			&& flag_var == 1)
		{
			nb_blocks++;
			flag_var = 0;
		}
	}
	return (nb_blocks);
}

char	*substitute_block(char *token, int index)
{
	int		i;
	char	*new_block;
	char	*var_name;

	i = index;
	if (token[index + 1] == '?')
		function_exstat();
	while (!ft_iswhitespace(token[i]) && token[i] != '\"' && token[i] != '\'')
		i++;
	var_name = ft_substr(token, index + 1, i - index);
	new_block = ft_calloc(ft_strlen(getenv(var_name)), sizeof(char));
	new_block = getenv(var_name);
}

int	create_blocks(char *token, char **blocks)
{
	int	i;
	int	i_block;

	i = 0;
	while (token[i])
	{
		while (token[i]
			&& !(token[i] == '$' && !single_quoted(token, i) && token[i + 1]))
			blocks[i][i_block] = token[i++];
		if (token[i])
		{
			blocks[i_block] = substitute_block(token, i);
			i += ft_strlen(blocks[i_block++]);
		}
	}
}

char	*substitute_variable(char *token)
{
	int		nb_blocks;
	char	**blocks;
	char	*new_token;

	nb_blocks = count_nbblocks(token);
	blocks = ft_calloc(nb_blocks, sizeof(char *));
	create_blocks(token, blocks);
// 	new_token = create_newtoken(blocks);

	// int		i;
	// int		nb_blocks;
	// char	**blocks;

	// i = 0;
	// nb_tokens = 0;
	// if (token[0] != '$')
	// 	nb_tokens++;
	// while (token[i])
	// {
	// 	if (token[i] == '$' && !single_quoted(token, i))
	// 	{
	// 		nb_tokens++;
	// 		while (token[i] && token[i] != '\'' && token[i] != '\"'
	// 			&& token[i] != '$' && !ft_iswhitespace(token[i]))
	// 			i++;
	// 	}
	// 	if (token[i] && token[i] != '$'
	// 		&& (token [i + 1] && token[i] == '\"' && token[i + 1] == '$'))
	// 		nb_tokens++;
	// 	i++;
	// }
	// var_division = ft_calloc(nb_tokens, sizeof(char *));

}

//This considers "str" was allocated (it frees it).
char	*ft_strtrim_whitespaces(char *str)
{
	int		i_start;
	int		i_end;
	char	*str_cpy;

	i_start = 0;
	while (str[i_start] && ft_iswhitespace(str[i_start]))
		i_start++;
	i_end = ft_strlen(str) - 1;
	while (str[i_end] && ft_iswhitespace(str[i_end]))
		i_end--;
	str_cpy = ft_substr(str, i_start, i_end - i_start + 1);
	free (str);
	return (str_cpy);
}
