#include "../minishell.h"

int	is_sort(int *tab, char **env)
{
	int	i;

	i = 0;
	while (env[i] && env[i + 1])
	{
		if (ft_strcmp_export(env[tab[i]], env[tab[i + 1]]) > 0)
			return (0);
		i++;
	}
	return (1);
}

int	*sort_tab(int *tab, char **env)
{
	int	i;
	int	tmp;

	while (is_sort(tab, env) == 0)
	{
		i = 0;
		while (env[i] && env[i + 1])
		{
			if (ft_strcmp(env[tab[i]], env[tab[i + 1]]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
	}
	return (tab);
}

void	ft_print_var_export(char *str)
{
	int	i;
	int	key;

	i = 0;
	key = 0;
	printf("declare -x ");
	while (str[i])
	{
		printf("%c", str[i]);
		if (str[i] == '=' && key == 0)
		{
			key = 1;
			printf("\"");
		}
		i++;
	}
	if (key == 1)
		printf("\"");
}

void	print_export_declare(t_data_mini *data)
{
	int	*tab;
	int	i;

	i = 0;
	tab = init_tab(data->env);
	tab = sort_tab(tab, data->env);
	while (data->env[i])
	{
		ft_print_var_export(data->env[tab[i]]);
		printf("\n");
		i++;
	}
	free(tab);
}

void	ft_export(t_data_mini *data)
{
	int	i;

	i = 1;
	if (data->list_cmd->list_token[1] == NULL)
	{
		print_export_declare(data);
		return ;
	}
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
		ft_export_var(data, data->list_cmd->list_token[i]);
		i++;
	}
	data->dollar = 0;
}
