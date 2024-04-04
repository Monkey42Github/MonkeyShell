#include"../minishell.h"

int	ft_atoi(const char *str)
{
	int	neg;
	int	i;
	int	num;

	i = 0;
	neg = 1;
	num = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		num = num * 10 + (str[i] - 48);
		i++;
	}
	return (num * neg);
}

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_data_mini *data)
{
	if (data->nb_cmd > 1)
		return ;
	if (data->list_cmd->nb_token >= 2
		&& ft_is_digit(data->list_cmd->list_token[1]) == 0)
	{
		data->dollar = 1;
		write(2, "exit: l: numeric argument required\n", 36);
		exit(255);
	}
	if (data->list_cmd->nb_token >= 3)
	{
		data->dollar = 1;
		write(2, "exit: too many arguments\n", 26);
		return ;
	}
	if (data->list_cmd->nb_token == 2)
	{
		printf("exit\n");
		exit(ft_atoi(data->list_cmd->list_token[1]));
	}
	printf("exit\n");
	exit(0);
}
