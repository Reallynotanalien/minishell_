# include "../../includes/minishell.h"

//🌷K: Quand on écrit quelque chose entre quotes genre : "Allo j'aime 42" et 
// qu'il y a une quote entre les quotes, ça donne le warning de unclosed 
//quotes mais ça devrait pas 
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

//This works, but has too many lines
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