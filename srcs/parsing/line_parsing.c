# include "../../includes/minishell.h"

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

// 👷 E : Working on this ! 👷
//Finds the lenght of the given string without useless spaces
// int	get_strlen()
// {

// }

//🌷K: J'ai essayé de le mettre devant le readline, mais il y a 2 problèmes:
//1- For some reason, quand on fait ça et qu'une erreur arrive dans le programme
//tout ferme???
//2- Si on remplace la ligne directement, la ligne qui va être ajoutée à 
//l'history sera pas bonne (ça va être la nouvelle version changée). Donc je 
//pense qu'il faudrait faire une copie de la ligne sans les espaces et c'est ça
//que je vais envoyer à split_tokens, mais on garde quand même la vraie ligne en
//mémoire 🌷
//This works, except it leaves a single space at the end of the str
char	*remove_spaces(char *str)
{
	char	*new_str;
	int		i;
	int		str_len;

	if (!str || !str[0] || parse_quotes(str) == ERROR)
		return (free (str), NULL);
	i = -1;
	str_len = 0;
	while (str[++i])
		if (!ft_iswhitespace(str[i]) || double_quoted(str, i) 
			|| single_quoted(str, i)
			|| (i != 0 && !ft_iswhitespace(str[i - 1])))
			str_len++;
	new_str = ft_calloc(str_len + 1, sizeof(char));
	if (!new_str)
		return (free (str), NULL);
	i = -1;
	str_len = 0;
	while (str[++i])
		if (!ft_iswhitespace(str[i])
			|| (i != 0 && !ft_iswhitespace(str[i - 1])))
			new_str[str_len++] = str[i];
	return (new_str);
}
