# include "../../includes/minishell.h"

void	exec(void)
{
	printf("Execution happens here because error is set to %i\n",
		use_data()->error_flag);
}
