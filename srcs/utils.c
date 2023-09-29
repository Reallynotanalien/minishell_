#include "../includes/minishell.h"
#include "../includes/parsing.h"

/*Checks if the print flag is activated, and if it is, prints the messages 
found along the program. This should help finding where the program stops
if there is a bug.*/
void	print_progress(int printer, char *message)
{
	if (printer == YES)
		printf("%s\n", message);
}

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
