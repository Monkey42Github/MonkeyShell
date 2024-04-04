#include "../minishell.h"

void	drop_quotes(char *str)
{
	char	*str_copie;
	int		i;
	int		ii;
	char	c;

	str_copie = malloc(ft_strlen(str) + 1);
	strcpy(str_copie, str);
	i = 0;
	ii = 0;
	while (str_copie[i])
	{
		if (str_copie[i] == '\'' || str_copie[i] == '\"')
		{
			c = str_copie[i++];
			while (str_copie[i] != c && str_copie[i])
				str[ii++] = str_copie[i++];
			i++;
		}
		else
			str[ii++] = str_copie[i++];
	}
	str[ii] = 0;
	free(str_copie);
}

void	ft_clean_quotes(t_data_mini *data)
{
	int	i;
	int	ii;

	i = 0;
	while (i++ < data->nb_cmd)
	{
		ii = 0;
		if (ft_strcmp(data->list_cmd->list_token[ii], "\"\"") == 0
			|| ft_strcmp(data->list_cmd->list_token[ii], "\'\'") == 0)
		{
			data->list_cmd->list_token[ii] = malloc(20);
			data->list_cmd->list_token[ii++] = " ";
		}
		while (data->list_cmd->list_token[ii])
			drop_quotes(data->list_cmd->list_token[ii++]);
		data->list_cmd = data->list_cmd->next;
	}
}

void	initial_vars_dollar(int *i, int *ii)
{
	*i = 0;
	*ii = 0;
}
