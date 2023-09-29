#include "../includes/minishell.h"
#include "../includes/parsing.h"
#include "../includes/exec.h"

int	main(int argc, char **argv)//❌ (argc argv)
{
	//t_dlist	*tokens;
	char	*line;
	int		i;//❌
	
	//tokens = malloc(sizeof(t_dlist));
	signals();
	//mini parsing
	while (1)
	{
		line = readline("minishell$> ");
		if (line && *line)
		{
			//mettre add history après l'exec? pck si la commande est pas
			//trouvée avec bash il la montre pas dans l'historique
			parsing(line);
			if (use_data()->error_flag != ERROR)
				exec();
			add_history(line);
			//free tokens
		}
		if (line == NULL)
			exit_program();
		free(line);
	}
	cleanup();
	return (0);
}
