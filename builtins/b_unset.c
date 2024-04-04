#include "../minishell.h"

char	**malloc_new_env_unset(char **env, char *var_to_unset)
{
	char	**new_env;
	char	*var_to_check;
	int		i;
	int		top_var_exist;

	i = 0;
	while (env[i])
	{
		var_to_check = get_var_to_add(env[i]);
		if (ft_strcmp(var_to_unset, var_to_check) == 0)
			top_var_exist = 1;
		free(var_to_check);
		i++;
	}
	if (top_var_exist == 1)
		new_env = malloc((i) * sizeof(char *));
	else
		new_env = malloc((i + 1) * sizeof(char *));
	return (new_env);
}

void	ft_unset_var(t_data_mini *data, char *token)
{
	char	*var_to_check;
	char	**new_env;
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	new_env = malloc_new_env_unset(data->env, token);
	while (data->env[ii])
	{
		var_to_check = get_var_to_add(data->env[ii]);
		if (ft_strcmp(token, var_to_check) != 0)
		{
			new_env[i] = ft_strdup(data->env[ii]);
			i++;
		}
		ii++;
		free(var_to_check);
	}
	ft_free_tab(data->env);
	new_env[i] = 0;
	data->env = new_env;
}

void	ft_unset(t_data_mini *data)
{
	int	i;

	i = 1;
	while (data->list_cmd->list_token[i])
	{
		if (verif_token_export(data->list_cmd->list_token[i]) == 0)
		{
			data->dollar = 1;
			return ;
		}
		i++;
	}
	i = 1;
	while (data->list_cmd->list_token[i])
	{
		ft_unset_var(data, data->list_cmd->list_token[i]);
		i++;
	}
	data->dollar = 0;
}
