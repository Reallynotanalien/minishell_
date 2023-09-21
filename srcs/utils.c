#include "../includes/minishell.h"

/*Checks if the print flag is activated, and if it is, prints the messages 
found along the program. This should help finding where the program stops
if there is a bug.*/
void	print_progress(int printer, char *message)
{
	if (printer == YES)
		printf("%s\n", message);
}
