#include"../minishell.h"

void	add_space_pipe_bis(char *str, char *new_str, int	*i, int *ii)
{
	char	type_quote;

	type_quote = str[*i];
	new_str[*ii] = str[*i];
	*i = *i + 1;
	*ii = *ii + 1;
	while (str[*i] != type_quote)
	{
		new_str[*ii] = str[*i];
		*i = *i + 1;
		*ii = *ii + 1;
	}
}

void	add_space_pipe(t_data_mini *data)
{
	char	*new_str;
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	new_str = malloc(sizeof(char) * \
	((ft_strlen(data->cmd) + count_p(data->cmd) * 2) + 1));
	while (data->cmd[i])
	{
		if (data->cmd[i] == '\'' || data->cmd[i] == '\"')
			add_space_pipe_bis(data->cmd, new_str, &i, &ii);
		if (data->cmd[i] != '|')
			new_str[ii++] = data->cmd[i++];
		else
		{
			new_str[ii++] = ' ';
			new_str[ii++] = '|';
			new_str[ii++] = ' ';
			i++;
		}
	}
	new_str[ii] = '\0';
	free(data->cmd);
	data->cmd = new_str;
}

void	end_add_space(t_data_mini *data, int ii, char *new_cmd)
{
	new_cmd[ii] = '\0';
	free(data->cmd);
	data->cmd = new_cmd;
}

void	add_space_redir(t_data_mini *data)
{
	char	*new_cmd;
	int		i;
	int		ii;

	i = 0;
	ii = 0;
	new_cmd = malloc(sizeof(char) * \
	(strlen(data->cmd) + count_redir(data->cmd) * 2 +1));
	while (data->cmd[i])
	{
		if (data->cmd[i] == '\'' || data->cmd[i] == '\"')
			add_space_pipe_bis(data->cmd, new_cmd, &i, &ii);
		if (data->cmd[i] != '<' && data->cmd[i] != '>')
			new_cmd[ii++] = data->cmd[i++];
		else
		{
			new_cmd[ii++] = ' ';
			new_cmd[ii++] = data->cmd[i++];
			if (data->cmd[i] == data->cmd[i - 1])
				new_cmd[ii++] = data->cmd[i++];
			new_cmd[ii++] = ' ';
		}
	}
	end_add_space(data, ii, new_cmd);
}
