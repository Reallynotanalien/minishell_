# include "../../../includes/minishell.h"

t_command	*create_command(void)
{
	t_command	*new;

	new = ft_calloc(sizeof(t_command), 1);
	if (!new)
		return (NULL);
	new->next = NULL;
	return (new);
}

t_command	*add_command(char *command, int infile, int outfile)
{
	t_command	*new;
	t_command	*next;

	if (command == NULL)
		return (NULL);
	new = create_command();
	if (!new)
		return (NULL);
	new->cmd = ft_strdup(command);
	new->infile = infile;
	new->outfile = outfile;
	if (use_data()->cmd == NULL)
		use_data()->cmd = new;
	else
	{
		next = use_data()->cmd;
		while (next->next != NULL)
			next = next->next;
		next->next = new;
	}
	return (use_data()->cmd);
}

void	free_commands_if_not_empty(void)
{
	t_command	*temp;

	if (!use_data()->cmd)
		return ;
	while (use_data()->cmd)
	{
		temp = use_data()->cmd->next;
		free(use_data()->cmd);
		use_data()->cmd = temp;
	}
}

void	view_commands(void)
{
	t_command	*cmd;
	int			i;

	i = 1;
	cmd = use_data()->cmd;
	while (cmd)
	{
		printf("----------------\n");
		printf("command%d:[%s]\n", i++, (char *)cmd->cmd);
		printf("infile no: %i\n", cmd->infile);
		printf("outfile no: %i\n", cmd->outfile);
		cmd = cmd->next;
	}
}
