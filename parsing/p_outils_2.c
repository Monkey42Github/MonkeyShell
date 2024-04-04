#include"../minishell.h"

void	supp_char(t_data_mini *data, char c)
{
	int	i;

	i = 0;
	while (data->cmd[i])
	{
		if (data->cmd[i] == '\'')
		{
			while (data->cmd[i] != '\'' && data->cmd[i])
				i++;
		}
		if (data->cmd[i] == '\"')
		{
			while (data->cmd[i] != '\"' && data->cmd[i])
				i++;
		}
		if (data->cmd[i] == c)
			data->cmd[i] = ' ';
		i++;
	}
}

int	cmd_empty(char *str)
{	
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}
