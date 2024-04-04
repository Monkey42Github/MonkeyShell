#include "../minishell.h"

char	*get_var_pwd(t_data_mini *data)
{
	char	*var_to_check;
	int		i;

	i = 0;
	while (data->env[i])
	{
		var_to_check = get_var_to_add(data->env[i]);
		if (ft_strcmp("PWD", var_to_check) == 0)
		{
			free(var_to_check);
			return (&data->env[i][4]);
		}
		i++;
		free(var_to_check);
	}
	return (NULL);
}

void	ft_pwd(t_data_mini *data)
{
	(void)(data);
	printf("%s\n", get_var_pwd(data));
	exit(0);
}
