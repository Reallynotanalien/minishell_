# include "../../includes/minishell.h"
# include "../../includes/exec.h"

void	exec()
{
	printf("Execution happens here because error is set to %i\n",
		use_data()->error_flag);
}
