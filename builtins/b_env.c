#include "../minishell.h"

int	has_value(char	*str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=')
			return (1);
		i++;
	}
	return (0);
}

void	ft_env(t_data_mini *data)
{
	int	i;

	i = 0;
	while (data->env[i])
	{
		if (has_value(data->env[i]) == 1)
			printf("%s\n", data->env[i]);
		i++;
	}
	exit(0);
}
