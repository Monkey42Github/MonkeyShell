#include "../minishell.h"

int	ft_is_flag_n(char *str)
{
	int	i;

	i = 0;
	if (str[i++] != '-')
		return (0);
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo_1(t_data_mini *data)
{
	int	i;
	int	top;

	i = 1;
	top = 0;
	if (data->list_cmd->list_token[i])
	{
		while (data->list_cmd->list_token[i]
			&& ft_is_flag_n(data->list_cmd->list_token[i++]))
			top = 1;
		i--;
		while (data->list_cmd->list_token[i])
		{
			printf("%s", data->list_cmd->list_token[i]);
			if (data->list_cmd->list_token[i + 1])
				printf(" ");
			i++;
		}
		if (top == 0)
			printf("\n");
	}
	else
		printf("\n");
	exit(0);
}

void	ft_echo_2(t_data_mini *data)
{
	int	i;
	int	top;

	i = 1;
	top = 0;
	if (data->list_cmd->cmd_redir[i])
	{
		while (data->list_cmd->cmd_redir[i]
			&& ft_is_flag_n(data->list_cmd->cmd_redir[i++]))
			top = 1;
		i--;
		while (data->list_cmd->cmd_redir[i])
		{
			printf("%s", data->list_cmd->cmd_redir[i]);
			if (data->list_cmd->cmd_redir[i + 1])
				printf(" ");
			i++;
		}
		if (top == 0)
			printf("\n");
	}
	else
		printf("\n");
	exit(0);
}

void	ft_echo(t_data_mini *data)
{
	if (data->list_cmd->top_redir == 0)
		ft_echo_1(data);
	else
		ft_echo_2(data);
}
