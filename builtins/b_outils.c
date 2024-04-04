#include "../minishell.h"

int	ft_search_pwd(t_data_mini *data, char *var)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (data->env[i])
	{
		while (data->env[i][j] != '=')
			j++;
		str = malloc(sizeof(char) * j + 1);
		str[j] = '\0';
		j = 0;
		while (data->env[i][j++] != '=')
			str[j] = data->env[i][j];
		if (ft_strcmp(str, var) == 0)
		{
			free(str);
			return (i);
		}
		free(str);
		i++;
	}
	return (-1);
}

char	*ft_take_value(t_data_mini *data, char *var)
{
	char	*home;
	int		i;
	int		j;
	int		a;

	i = ft_search_pwd(data, var);
	j = 0;
	while (data->env[i][j] != '=')
		j++;
	j++;
	a = 0;
	while (data->env[i][j])
	{
		j++;
		a++;
	}
	home = malloc(sizeof(char) * (a + 1));
	j = j - a;
	a = 0;
	while (data->env[i][j])
	{
		home[a++] = data->env[i][j++];
	}
	home[a] = '\0';
	return (home);
}
