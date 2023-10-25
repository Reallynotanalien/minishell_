# include "../includes/minishell.h"

void	init_data(t_data *data)
{
	data->cmd = NULL;
	data->error_flag = 0; //?
	data->heredoc_flag = 0;
	data->line = NULL;
	data->line_cpy = NULL;
	// data->new_attributes;	//? (Is this allocated)
	data->new_env = NULL;	//?
	// data->old_attributes;	//? (Is this allocated)
	data->token = NULL;
}
