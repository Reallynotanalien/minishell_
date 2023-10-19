# include "../../includes/minishell.h"

t_token	*create_token(void)
{
	t_token	*new;

	new = ft_calloc(sizeof(t_token), 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

t_token	*add_token(char *token)
{
	t_token	*new;
	t_token	*next;

	if (token == NULL)
		return (NULL);
	new = create_token();
	if (!new)
		return (NULL);
	new->token = ft_strdup(token);
	if (use_data()->token == NULL)
		use_data()->token = new;
	else
	{
		next = use_data()->token;
		while (next->next != NULL)
			next = next->next;
		next->next = new;
	}
	return (use_data()->token);
}

void	free_tokens_if_not_empty(void)
{
	t_token	*temp;

	if (!use_data()->token)
		return ;
	while (use_data()->token)
	{
		temp = use_data()->token->next;
		free(use_data()->token);
		use_data()->token = temp;
	}
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

void	view_list(void)
{
	t_token	*tokens;
	int		i;

	i = 1;
	tokens = use_data()->token;
	while (tokens)
	{
		printf("----------------\n");
		printf("token%d:[%s]\n", i++, (char *)tokens->token);
		printf("type: %d\n", tokens->type);
		if (!tokens->next)
			return ;
		tokens = tokens->next;
	}
}
