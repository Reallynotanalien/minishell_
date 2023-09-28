#include "../includes/minishell.h"
#include "../includes/parsing.h"
#include "../includes/exec.h"

int	main(void)
{
	//possiblement à modifier, selon la structure qu'on va utiliser
	t_shell		*sh;
	//t_dlist	*tokens;
	char	*line;
	
	sh = malloc(sizeof(t_shell));
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
			//parsing(line, tokens);
			parsing(line, sh);
			if (sh->error_flag != ERROR)
				exec(sh);
			add_history(line);
			//free tokens
		}
		if (line == NULL)
			exit_program(sh);
		free(line);
	}
	cleanup(sh);
	return (0);
}
