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
	printf("%s\n", message);
	// write(2, "\n", 1);
	return (ERROR);
}

//Returns 1 if 'index' is part of a single-quoted string. Else returns 0.
/*Counts the number of single quotes until index is reached,
checks if they are already closed (even number of quotes), 
if it is double_quoted (therefore not interpreted) and if there 
is another single quote further in the string. */
int	single_quoted(char *str, int index)
{
	int	quoted;
	int	i;
	int	i_tmp;

	quoted = 0;
	i = 0;
	while (str[i] && i < index)
	{
		if (str[i] == '\'' && double_quoted(str, i) == 0)
		{
			i_tmp = i;
			while (str[i_tmp] && str[i_tmp] != '\'')
				i_tmp++;
			if (i_tmp == (int)ft_strlen(str))
				quoted = 0;
			else
				quoted = 1;
		}
		i++;
	}
	if (quoted % 2 != 0 && ft_strchr(&str[i], '\''))
		return (1);
	return (0);
}

//Returns 1 if 'index' is part of a double-quoted string. Else returns 0.
int	double_quoted(char *str, int index)
{
	int	quoted;
	int	i;
	int	i_tmp;

	quoted = 0;
	i = 0;
	while (str[i] && i < index)
	{
		if (str[i] == '"' && single_quoted(str, i) == 0)
		{
			i_tmp = i;
			while (str[i_tmp] && str[i_tmp] != '\"')
				i_tmp++;
			if (i_tmp == (int)ft_strlen(str))
				quoted = 0;
			else
				quoted = 1;
		}
		i++;
	}
	if (quoted % 2 != 0 && ft_strchr(&str[i], '\"'))
		return (1);
	return (0);
}