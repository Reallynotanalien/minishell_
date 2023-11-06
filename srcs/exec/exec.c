# include "../../includes/minishell.h"

void	pipex(t_command *cmd)
{
	printf("pipex %s\n", cmd->cmd[0]);
	// dup2(cmd->infile, STDIN_FILENO);
	// close(cmd->infile);
	// while (cmd)
	// {
	// 	if (cmd->next)
	// 	{
	// 	}
	// 	else
	// 	if (cmd->next)
	// 		cmd = cmd->next;
	// 	else
	// 		break ;
	// }
}

void	exec(t_command *cmd)
{
	printf("%s\n", cmd->cmd[0]);
	printf("if (absolute_path)\n");
	printf("if (builtin)\n");
	printf("else: pipex\n");
}
