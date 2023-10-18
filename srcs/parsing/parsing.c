# include "../../includes/minishell.h"

/*Checks if the minishell args are valid and makes a copy
of the env variable to be used later.*/
int	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (printf(ARGC_ERROR), ERROR);
	use_data()->new_env = env;
	if (!use_data()->new_env)
		return (printf(ENV_ERROR), ERROR);
	if (!argv)
		return (printf(ARGV_ERROR), ERROR);
	return (0);
}

int	line_parsing(void)
{
	//1- Look if all the quotes are closed if not return ERROR
	//2- Cut the line into tokens
	if (split_tokens() == ERROR)
		return (ERROR);
	//3- Iterate through each token to make sure they are valid
	//and add them to the command struct
	return (0);
}

int	parse_quotes(char *str)
{
	int	i;
	int	single_quotes;
	int	double_quotes;

	single_quotes = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '\'')
			single_quotes++;
	double_quotes = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '\"')
			double_quotes ++;
	if (single_quotes % 2 != 0 || double_quotes % 2 != 0)
		return (print_error("minishell: found unclosed quotation marks"));
	return (0);
}

int	is_end(char *str, int index)
{
	while (str[index])
	{
		if (!ft_iswhitespace(str[index]))
			return (0);
		index++;
	}
	return (1);
}

//This works, except it leaves a single space at the end of the str
char	*remove_spaces(char *str)
{
	char	*new_str;
	int		i;
	int		str_len;

	if (!str || !str[0] || parse_quotes(str) == ERROR)
	{
		free (str);
		return (NULL);
	}
	i = -1;
	str_len = 0;
	while (str[++i])
		if ((!ft_iswhitespace(str[i]) || double_quoted(str, i) 
				|| single_quoted(str, i)) && !is_end(str, i))
			str_len++;
	new_str = ft_calloc(str_len + 1, sizeof(char));
	if (!new_str)
	{
		free (str);
		return (NULL);
	}
	i = -1;
	str_len = 0;
	while (str[++i])
		if (double_quoted(str, i) || single_quoted(str, i)
			|| (!is_end(str, i) && (!ft_iswhitespace(str[i])
					|| (i != 0 && !ft_iswhitespace(str[i - 1])))))
			new_str[str_len++] = str[i];
	free (str);
	return (new_str);
}
