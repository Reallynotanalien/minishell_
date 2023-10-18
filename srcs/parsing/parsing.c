# include "../../includes/minishell.h"

/*Checks if the minishell args are valid and makes a copy
of the env variable to be used later.*/
int	main_parsing(int argc, char **argv, char **env)
{
	if (argc != 1)
		return (print_error(ARGC_ERROR));
	use_data()->new_env = env;
	if (!use_data()->new_env)
		return (print_error(ENV_ERROR));
	if (!argv)
		return (print_error(ARGV_ERROR));
	return (0);
}

/*First checks if all the quotes are closed, if not, returns ERROR.*/
int	line_parsing(void)
{
	//1- Look if all the quotes are closed if not return ERROR
	//then deletes all superfluous spaces and changes the line 
	//accordingly. 
	//2- Cut the line into tokens
	if (split_tokens() == ERROR)
		return (ERROR);
	view_list();
	//3- Iterate through each token to make sure they are valid
	//and add them to the command struct
	free_tokens_if_not_empty();
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

// 👷 E : Working on this ! 👷
//Finds the lenght of the given string without useless spaces
// int	get_strlen()
// {

// }

//This works, except it leaves a single space at the end of the str
char	*remove_spaces(char *str)
{
	char	*new_str;
	int		i;
	int		str_len;

	if (!str || !str[0] || parse_quotes(str) == ERROR)
		return (NULL);
	i = -1;
	str_len = 0;
	while (str[++i])
		if (!ft_iswhitespace(str[i]) || double_quoted(str, i) 
			|| single_quoted(str, i)
			|| (i != 0 && !ft_iswhitespace(str[i - 1])))
			str_len++;
	new_str = ft_calloc(str_len + 1, sizeof(char));
	if (!new_str)
	{
		print_error("minishell: could not allocate memory");
		return (NULL);
	}
	i = -1;
	str_len = 0;
	while (str[++i])
		if (!ft_iswhitespace(str[i])
			|| (i != 0 && !ft_iswhitespace(str[i - 1])))
			new_str[str_len++] = str[i];
	return (new_str);
}
