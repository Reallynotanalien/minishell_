# include "../../../includes/minishell.h"

int	parse_quotes(char *str)
{
	int	i;
	int	single_quotes;
	int	double_quotes;

	single_quotes = 0;
	i = -1;
	while (str[++i])
		if (str[i] == '\'' && !double_quoted(str, i))
			single_quotes++;
	double_quotes = 0;
	i = -1;
	while (str[++i] && !single_quoted(str, i))
		if (str[i] == '\"')
			double_quotes ++;
	if (single_quotes % 2 != 0 || double_quotes % 2 != 0)
		return (parsing_error(QUOTES_ERROR));
	return (0);
}

//Finds the lengh of str without whitespaces before, after or consecutive
int	find_lenght(char *str, int end)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (i < end && ft_iswhitespace(str[i]))
		i++;
	while (i < end)
	{
		while (i < end && !ft_iswhitespace(str[i]))
		{
			i++;
			len++;
		}
		if (i < end)
			len++;
		while (ft_iswhitespace(str[i]))
			i++;
	}
	return (len);
}

/*removes the unnecessary spaces from readline's return,
frees use_data()->line and saves the result in use_data()->line_cpy.*/
int	remove_spaces(char *str)
{
	int		i;
	int		end;
	int		i_new;
	char	*new_str;

	i = 0;
	while (str[i] && ft_iswhitespace(str[i]))
		i++;
	end = ft_strlen(str) - 1;
	while (ft_iswhitespace(str[end]))
		end--;
	new_str = ft_calloc(find_lenght(str, end + 1), sizeof(char));
	i_new = 0;
	while (i < end)
	{
		while (!ft_iswhitespace(str[i]))
			new_str[i_new++] = str[i++];
		if (i < end)
			new_str[i_new++] = ' ';
		while (ft_iswhitespace(str[i]))
			i++;
	}
	use_data()->line_cpy = new_str;
	return (EXIT_SUCCESS);
}
