
#include "../includes/minishell.h"
//intended to avoid conflicts (to be moved later)

//returns 1 if the character is an environment variable name delimiter.
int	is_delimiter(char c)
{
	if (!c || ft_iswhitespace(c) || c == '\''
		|| c == '\"' || c == '$' || c == '<' || c == '>' || c == '|'
		|| c == '?')
		return (1);
	return (0);
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

int	count_nbblocks(char *line)
{
	int	i;
	int	nb_blocks;
	int	flag_var;

	i = -1;
	if (line[0] == '$')
		nb_blocks = 0;
	else
		nb_blocks = 1;
	flag_var = 0;
	while (line[++i])
	{
		if (line[i] == '$' && !single_quoted(line, i) && line[i + 1])
		{
			nb_blocks++;
			flag_var = 1;
			i++;
		}
		if (flag_var == 1 && is_delimiter(line[i]))
		{
			nb_blocks++;
			flag_var = 0;
		}
	}
	return (nb_blocks);
}

//Substitutes 1 block (one variable)
int	substitute_block(char *line, int index, char **blocks, int i_block)
{
	int		i;
	char	*new_block;
	char	*var_name;

	i = index + 1;
	if (line[i] == '?')
		return (blocks[i_block] = ft_itoa(use_data()->exstat), 2);
	if (is_delimiter(line[i]))
		return (blocks[i_block] = ft_strdup("$"), 1);
	while (!is_delimiter(line[i]))
		i++;
	var_name = ft_substr(line, index + 1, i - index - 1);
	new_block = ft_strdup(getenv(var_name));
	if (!new_block)
		new_block = ft_strdup("");
	free (var_name);
	blocks[i_block] = new_block;
	return (i - index);
}

//Allocates one string by block and calls the corresponding function to substitute, if necessary, said block.
//A block is either a variable name(substitution) or a string(no substitution).
//A variable name is anything between a $ and 
//a whitespace, a redirection, a quote symbol, another $ or a null character (end of str).
void	create_blocks(char *line, char **blocks)
{
	int	i;
	int	i_block;
	int	len;

	i = 0;
	i_block = 0;
	if (line[0] == '$')
	{
		i += substitute_block(line, i, blocks, i_block);
		i_block++;
	}
	while (line[i])
	{
		len = 0;
		while (line[i + len] && !(line[i + len] == '$'
				&& !single_quoted(line, i + len)))
			len ++;
		if (line[i] != '$')
			blocks[i_block++] = ft_substr(line, i, len);
		i += len;
		if (line[i])
		{
			i += substitute_block(line, i, blocks, i_block);
			i_block++;
		}
	}
}

//takes the line in struct and does all substitutions
void	do_substitutions(char *line)
{
	int		nb_blocks;
	char	**blocks;
	char	*new_line;
	char	*tmp;
	int		i;

	nb_blocks = count_nbblocks(line);
	blocks = ft_calloc(nb_blocks, sizeof(char *));
	create_blocks(line, blocks);
	new_line = ft_strdup(blocks[0]);
	i = 1;
	while (i < nb_blocks)
	{
		tmp = new_line;
		new_line = ft_strjoin(new_line, blocks[i]);
		free (tmp);
		i++;
	}
	free (blocks);
	free (line);
	use_data()->line_cpy = new_line;
}

//This considers "str" was allocated (it frees it).
char	*ft_strtrim_whitespaces(char *str)
{
	int		i_start;
	int		i_end;
	char	*str_cpy;

	i_start = 0;
	while (str[i_start] && (ft_iswhitespace(str[i_start])
			|| !ft_isascii(str[i_start])))
		i_start++;
	i_end = ft_strlen(str) - 1;
	while (str[i_end] && (ft_iswhitespace(str[i_end])
			|| !ft_isascii(str[i_end])))
		i_end--;
	str_cpy = ft_substr(str, i_start, i_end - i_start + 1);
	free (str);
	return (str_cpy);
}
