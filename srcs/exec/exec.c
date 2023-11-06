# include "../../includes/minishell.h"

int	count_commands(t_command *cmd)
{
	int	i;

	i = 1;
	while (cmd->next)
	{
		cmd = cmd->next;
		i++;
	}
	return (i);
}

void	child_two(char **cmd)
{
	printf("child two: %s\n", cmd[0]);
}

void	pipex(char **cmd, int nb_cmds)
{
	while (nb_cmds > 1)
	{
		printf("%i\n", nb_cmds);
		printf("%s\n", cmd[0]);
		nb_cmds--;
	}
	child_two(cmd);
}

void	exec(t_command *cmd)
{
	int	nb_cmds;

	nb_cmds = count_commands(cmd);
	// dup2(cmd->infile, STDIN_FILENO);
	// close (cmd->infile);
	while (cmd)
	{
		printf("%s\n", cmd->cmd[0]);
		if (access(cmd->cmd[0], F_OK) == 0)
		{
			cmd->path = cmd->cmd[0];
			printf("is an absolute path\n");
		}
		else if (cmd->builtin_flag == YES)
			printf("is a builtin)\n");
		if (nb_cmds == 1)
			printf("execute the command directly\n");
		else
			pipex(cmd->cmd, nb_cmds);
		if (cmd->next)
			cmd = cmd->next;
		else
			break ;
	}
}
