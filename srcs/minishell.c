#include "../includes/minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	(void)env;

	use_data()->line_cpy = ft_strdup("this is a $USER|$USER test");
	use_data()->exstat = 1;
	do_substitutions(use_data()->line_cpy);
	printf("%s\n", use_data()->line_cpy);

	// if (main_parsing(argc, argv, env) == ERROR)
	// 	exit(1);
	// signals();
	// while (1)
	// {
	// 	use_data()->line = readline("minishell$> ");
	// 	if (use_data()->line && *use_data()->line)
	// 	{
	// 		line_parsing();
	// 		if (use_data()->error_flag != ERROR)
	// 			exec();
	// 		add_history(use_data()->line);
	// 	}
	// 	if (use_data()->line == NULL)
	// 		exit_program();
	// 	free(use_data()->line);
	// 	free_commands_if_not_empty();
	// 	if (use_data()->heredoc_flag == YES)
	// 		unlink(".here_doc");
	// }
	// cleanup();
	// return (0);
}
