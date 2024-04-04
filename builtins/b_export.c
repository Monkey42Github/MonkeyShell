#include "../minishell.h"

char	*get_var_to_add(char	*str)
{
	char	*var;
	int		i;

	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	var = malloc((i + 1) * sizeof(char));
	i = 0;
	while (str[i] && str[i] != '=')
	{
		var[i] = str[i];
		i++;
	}
	var[i] = '\0';
	return (var);
}

char	**malloc_new_env_export(char **env, char *var_to_add)
{
	char	**new_env;
	char	*var_to_check;
	int		i;
	int		top_var_exist;

	i = 0;
	while (env[i])
	{
		var_to_check = get_var_to_add(env[i]);
		if (ft_strcmp(var_to_add, var_to_check) == 0)
			top_var_exist = 1;
		free(var_to_check);
		i++;
	}
	if (top_var_exist == 1)
		new_env = malloc((i + 1) * sizeof(char *));
	else
		new_env = malloc((i + 2) * sizeof(char *));
	return (new_env);
}

int	ft_export_var_bis_1(t_data_mini *data, char **new_env, int *i, char *token)
{
	char	*var_to_add;
	char	*var_to_check;
	int		top_var_exist;

	top_var_exist = 0;
	var_to_add = get_var_to_add(token);
	while (data->env[*i])
	{
		var_to_check = get_var_to_add(data->env[*i]);
		if (ft_strcmp(var_to_add, var_to_check) == 0)
		{
			new_env[*i] = ft_strdup(token);
			top_var_exist = 1;
		}
		else
			new_env[*i] = ft_strdup(data->env[*i]);
		free(var_to_check);
		*i = *i + 1;
	}
	free(var_to_add);
	return (top_var_exist);
}

void	ft_export_var_bis_2(int i, char \
*token, int top_var_exist, char **new_env)
{
	if (top_var_exist == 0)
	{
		new_env[i] = ft_strdup(token);
		i++;
	}
	new_env[i] = 0;
}

int	did_var_exist(t_data_mini *data, char *token)
{
	char	*var_to_check;
	int		i;

	i = 0;
	while (data->env[i])
	{
		var_to_check = get_var_to_add(data->env[i]);
		if (ft_strcmp(token, var_to_check) == 0)
		{
			free(var_to_check);
			return (1);
		}
		i++;
		free(var_to_check);
	}
	return (0);
}
