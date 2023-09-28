# include "../../includes/minishell.h"
# include "../../includes/exec.h"

void	exec(t_shell *sh)
{
	printf("Execution happens here because error is set to %i\n",
		sh->error_flag);
}
