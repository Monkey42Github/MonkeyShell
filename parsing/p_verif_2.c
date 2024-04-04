#include"../minishell.h"

int	v_first_el_pipe(char	*str)
{
	int	i;

	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	if (str[i] == '|')
	{
		printf("parse error near `|'\n");
		return (1);
	}
	return (0);
}

int	v_multi_p_bis(char *str)
{
	int	laps_1;
	int	laps_2;

	laps_1 = 0;
	laps_2 = 0;
	while (str[1 + laps_1] == ' ')
		laps_1++;
	while (str[2 + laps_1 + laps_2] == ' ')
		laps_2++;
	if (str[1 + laps_1] == *str && str[2 + laps_1 + laps_2] == *str
		&& str[1 + laps_1] && str[2 + laps_1 + laps_2])
	{
		printf("parse error near `|'\n");
		return (1);
	}
	if (str[1 + laps_1] == *str && str[1 + laps_1])
	{
		printf("Bonus non fait (||)\n");
		return (1);
	}
	return (0);
}

int	v_multiple_pipe(char *str)
{
	char	q;
	char	*first;

	first = str;
	while (*str)
	{
		if (*str == '\'' || *str == '\"')
		{
			q = *str;
			str++;
			while (*str != q)
				str++;
		}
		if (*str == '|')
		{
			if (v_multi_p_bis(str) == 1)
				return (1);
		}
		str++;
	}
	str = first;
	return (0);
}

int	v_last_el_pipe(char	*str)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i--;
	if (str[i] == '|')
		return (1);
	return (0);
}

int	ft_verif_all(t_data_mini *data)
{
	if (cmd_empty(data->cmd) == 1)
	{
		free(data->cmd);
		return (0);
	}
	while (v_quote(data->cmd, '\'', '\"') == 0
		|| v_quote(data->cmd, '\"', '\'') == 0)
	{
		manage_quote_err(data);
		return (1);
	}
	if (verif_redir(data->cmd) != 1)
		return (0);
	if (v_first_el_pipe(data->cmd) == 1 || v_multiple_pipe(data->cmd) == 1)
		return (0);
	while (v_last_el_pipe(data->cmd) == 1)
	{
		manage_pipe(data);
		return (1);
	}
	return (2);
}
