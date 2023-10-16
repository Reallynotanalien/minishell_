
#include "../../includes/minishell.h"

/*The below function test the behavior of tokens surrounded by 
all symbols required to handle in the subject. 
Everything else is considered a string.
If an error should occur because of an invalid string, 
it will be handled by execve.
Only symbols right of the redirection is checked, as the error would 
have been caught earlier if a redirection symbol is present on left*/

int	next_isredirection(char *line, int index)
{
	if (ft_iswhitespace(line[index + 1]))
		index += 2;
	else
		index++;
	if ((!double_quoted(line, index) && !single_quoted(line, index))
		&& (line[index] == '<' || line[index] == '>' || line[index] == '|'))
		return (1);
	return (0);
}

//For '>>', index is the index of the first '>'.
int	parsing_redirection(char *line, int index)
{
	if (line[index + 1] && line[index] == line[index + 1])
		index ++;
	if (!line[index + 1])
		return (print_error
			("minishell: syntax error near unexpected token 'newline'"));
	if (index == 0 && line[index] == '|')
		return (print_error
			("minishell: syntax error near unexpected token '|'"));
	if ((next_isredirection(line, index) && line[index] == '|')
		|| (next_isredirection(line, index)
			&& next_isredirection(line, index + 1)))
	{
		if (ft_iswhitespace(line[index + 1]))
			index += 2;
		else
			index++;
		if (line[index + 1] && line[index] == line[index + 1])
			printf ("minishell: syntax error near unexpected token '%c%c'\n",
				line[index], line[index]);
		else
			printf ("minishell: syntax error near unexpected token '%c'\n",
				line[index]);
		return (ERROR);
	}
	return (0);
}

t_token	*newlst(char *token, int type)
{
	t_token	*first;

	first = ft_calloc(sizeof(t_token), 1);
	if (!first)
		return (NULL);
	first->token = token;
	first->type = type;
	first->next = NULL;
	return (first);
}

void	addlst(t_token *lst, char *token, int type)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token), 1);
	new->token = token;
	new->type = type;
	new->next = NULL;
	while (lst->next != NULL)
		lst = lst->next;
	lst->next = new;
}

/*Returns the adress of the previous token's node or 
NULL if there is no previous token.*/
t_token	*lstget_prev(t_token *lst, t_token *reference)
{
	t_token	*previous;

	while (lst != reference)
	{
		previous = lst;
		lst = lst->next;
	}
	if (previous == lst)
		return (NULL);
	return (previous);
}
