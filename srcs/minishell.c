#include "../includes/minishell.h"

int	main(int argc, char **argv)//❌ (argc argv)
{
	//possiblement à modifier, selon la structure qu'on va utiliser
	//t_dlist	*tokens;
	char	*line;
	int		i;//❌
	
	printf("%i\n", PRINTER);//❌
	//tokens = malloc(sizeof(t_dlist));
	signals();
	print_progress(PRINTER, SIGNALS_OK);//❌
	//mini parsing
	print_progress(PRINTER, GLOBAL_PARSING_OK);//❌
	i = 0;
	while (1)
	{
		if (argc != 1 && i <= argc)//❌
			line = argv[i];//❌
		else//❌
			line = readline("minishell$> ");
		print_progress(PRINTER, READLINE_OK);//❌
		if (line && *line)
		{
			//mettre add history après l'exec? pck si la commande est pas trouvée avec bash il la montre pas dans l'historique
			//parsing(line, tokens);
			print_progress(PRINTER, PARSING_OK);//❌
			if (argc != 1)//❌
				exec_test();//❌
			else//❌
				//exec
			print_progress(PRINTER, EXEC_OK);//❌
			add_history(line);
			print_progress(PRINTER, HISTORY_OK);//❌
			//free tokens
			print_progress(PRINTER, FREE_TOKENS_OK);//❌
		}
		if (!line)
			break ;
		free(line);
		print_progress(PRINTER, FREE_LINE_OK);//❌
	}
	print_progress(PRINTER, LOOP_ENDED);//❌
	rl_clear_history();
	print_progress(PRINTER, CLEAR_HISTORY_OK);//❌
	//free(tokens);
	return (0);
}
