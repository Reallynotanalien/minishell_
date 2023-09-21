#include "../includes/minishell.h"

int	main(void)
{
	//possiblement à modifier, selon la structure qu'on va utiliser
	//t_dlist	*tokens;
	char	*line;
	int		printer;

	printer = YES;
	//tokens = malloc(sizeof(t_dlist));
	//signals();
	print_progress(printer, SIGNALS_OK);
	//mini parsing
	print_progress(printer, GLOBAL_PARSING_OK);
	while (1)
	{
		line = readline("minishell$> ");
		print_progress(printer, READLINE_OK);
		if (line && *line)
		{
			//mettre add history après l'exec? pck si la commande est pas trouvée avec bash il la montre pas dans l'historique
			//parsing(line, tokens);
			print_progress(printer, PARSING_OK);
			//exec
			print_progress(printer, EXEC_OK);
			add_history(line);
			print_progress(printer, HISTORY_OK);
			//free tokens
			print_progress(printer, FREE_TOKENS_OK);
		}
		if (!line)
			break ;
		free(line);
		print_progress(printer, FREE_LINE_OK);
	}
	print_progress(printer, LOOP_ENDED);
	rl_clear_history();
	print_progress(printer, CLEAR_HISTORY_OK);
	//free(tokens);
	return (0);
}
