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
		return (parsing_error(QUOTES_ERROR));
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
