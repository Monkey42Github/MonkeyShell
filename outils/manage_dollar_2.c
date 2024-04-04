#include"../minishell.h"

void	end_manage_doll_inter(t_data_mini *data, int ii, char *new_cmd)
{
	new_cmd[ii] = 0;
	free(data->cmd);
	data->cmd = new_cmd;
}

void	manage_dollar_interog(t_data_mini *data)
{
	int		i;
	int		ii;
	int		iii;
	char	*new_cmd;
	char	*nb;

	i = 0;
	ii = 0;
	new_cmd = malloc((ft_strlen(data->cmd) * 2 + 1) * sizeof(char));
	while (data->cmd[i])
	{
		if (data->cmd[i] == '$' && data->cmd[i + 1] == '?')
		{
			iii = 0;
			i = i + 2;
			nb = ft_itoa(data->dollar);
			while (nb[iii])
			new_cmd[ii++] = nb[iii++];
			free(nb);
		}
		else
			new_cmd[ii++] = data->cmd[i++];
	}
	end_manage_doll_inter(data, ii, new_cmd);
}

void	end_manage_dollar(t_data_mini *data, char *tmp, char *new_cmd, int ii)
{
	char	*res;

	tmp[ii] = '\0';
	res = ft_strjoin(new_cmd, tmp);
	free(tmp);
	free(new_cmd);
	free(data->cmd);
	data->cmd = res;
}

void	manage_dollar_1(t_data_mini *data, char *tmp, int *i, int *ii)
{
	tmp[*ii] = data->cmd[*i];
	*ii = *ii + 1;
	*i = *i + 1;
	while (data->cmd[*i] != '\'')
	{
		tmp[*ii] = data->cmd[*i];
		*ii = *ii + 1;
		*i = *i + 1;
	}
	tmp[*ii] = data->cmd[*i];
	*ii = *ii + 1;
	tmp[*ii] = 0;
}

void	manage_dollar(t_data_mini *data)
{
	int		i;
	int		ii;
	char	*new_cmd;
	char	*tmp;

	new_cmd = NULL;
	manage_dollar_interog(data);
	tmp = malloc((ft_strlen(data->cmd) + 1) * sizeof(char));
	initial_vars_dollar(&i, &ii);
	while (data->cmd[i])
	{
		if (data->cmd[i] == '\'')
			manage_dollar_1(data, tmp, &i, &ii);
		else if (data->cmd[i] == '$' )
		{
			tmp[ii] = '\0';
			ii = 0;
			new_cmd = ft_strjoin_33(new_cmd, tmp, \
				get_new_value(get_var(&data->cmd[i], &i), data->env));
		}
		else
			tmp[ii++] = data->cmd[i];
		i++;
	}
	end_manage_dollar(data, tmp, new_cmd, ii);
}
