#include "../includes/minishell.h"

int	main(void)
{
	//possiblement à modifier, selon la structure qu'on va utiliser
	//t_dlist	*tokens;
	char	*line;

	//tokens = malloc(sizeof(t_dlist));
	//signals();
	while (1)
	{
		line = readline("minishell$> ");
		if (line && *line)
		{
			//mettre add history après l'exec? pck si la commande est pas trouvée avec bash il la montre pas dans l'historique
			add_history(line);
			//parsing(line, tokens);
		}
		if (!line)
			break ;
		free(line);
	}
	rl_clear_history();
	//free(tokens);
	return (0);
}