#include "../includes/minishell.h"
#include "../includes/parsing.h"

t_data	*use_data(void)
{
	static t_data	*data;

	if (data == NULL)
	{
		data = malloc(sizeof(t_data));
		init_data(data);
	}
	return (data);
}

int	print_error(char *message)
{
	write(2, &message, sizeof(message));
	write(2, "\n", 1);
	return (ERROR);
}
