#include "../minishell.h"

void	ft_export_var(t_data_mini *data, char *token)
{
	char	*var_to_add;
	char	**new_env;
	int		i;
	int		top_var_exist;

	i = 0;
	var_to_add = get_var_to_add(token);
	new_env = malloc_new_env_export(data->env, var_to_add);
	free(var_to_add);
	top_var_exist = ft_export_var_bis_1(data, new_env, &i, token);
	ft_export_var_bis_2(i, token, top_var_exist, new_env);
	ft_free_tab(data->env);
	data->env = new_env;
}

int	is_valid_char(char c)
{
	if ((c >= '0' && c <= '9'))
		return (1);
	if ((c >= 'a' && c <= 'z'))
		return (1);
	if ((c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

int	is_only_digit(char *token)
{
	int	i;

	i = 0;
	while (token[i] && token[i] != '=')
	{
		if ((token[i] < '0' || token[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

int	verif_token_export(char *token)
{
	int	i;

	i = 0;
	if (is_only_digit(token) == 1)
	{
		printf("export: `%s': not a valid identifier \n", token);
		return (0);
	}
	i = 0;
	while (token[i] && token[i] != '=')
	{
		if (is_valid_char(token[i]) == 0)
		{
			printf("export: `%s': not a valid identifier \n", token);
			return (0);
		}
		i++;
	}
	return (1);
}

int	*init_tab(char **env)
{
	int	*tab;
	int	size;

	size = 0;
	while (env[size])
		size++;
	tab = malloc((size + 1) * sizeof(int));
	size = 0;
	while (env[size])
	{
		tab[size] = size;
		size++;
	}
	return (tab);
}
