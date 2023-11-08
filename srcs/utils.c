#include "../includes/minishell.h"
#include "../includes/parsing.h"

t_data	*use_data(void)
{
	static t_data	*data;

	if (data == NULL)
	{
		data = malloc(sizeof(t_data));
		init_data(data);
	}
	return (data);
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
		if (i > 2)
			printf("prev:[%s]\n", (char *)tokens->prev->token);
		if (!tokens->next)
			return ;
		tokens = tokens->next;
	}
}

char	*ft_strlower(char *str)
{
	int		i;
	char	*new_str;

	new_str = ft_calloc(ft_strlen(str), sizeof(char));
	i = -1;
	while (str[++i])
		new_str[i] = ft_tolower(str[i]);
	return (new_str);
}
