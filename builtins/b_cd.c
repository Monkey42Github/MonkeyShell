#include "../minishell.h"

char	*get_var_home(t_data_mini *data)
{
	char	*var_to_check;
	int		i;

	i = 0;
	while (data->env[i])
	{
		var_to_check = get_var_to_add(data->env[i]);
		if (ft_strcmp("HOME", var_to_check) == 0)
		{
			free(var_to_check);
			return (&data->env[i][5]);
		}
		i++;
		free(var_to_check);
	}
	return (NULL);
}

void	ft_cd_bis(t_data_mini *data)
{
	char	*home;
	char	*new_path;
	char	*pwd;
	int		ret;

	home = get_var_home(data);
	if (home != NULL)
	{
		ret = chdir(home);
		if (ret == -1)
		{
			printf("cd: %s: No such file or directory\n", home);
			data->dollar = 1;
			return ;
		}
		data->dollar = 0;
		pwd = getcwd(NULL, 0);
		new_path = ft_strjoin("PWD=", pwd);
		ft_export_var(data, new_path);
		free(pwd);
		free(new_path);
		return ;
	}
	data->dollar = 1;
	printf("cd: HOME not set\n");
}

void	manage_tilde(t_data_mini *data)
{
	char	*home;
	char	*new_arg;

	home = get_var_home(data);
	new_arg = ft_strjoin(home, &data->list_cmd->list_token[1][1]);
	data->list_cmd->list_token[1] = new_arg;
	free(new_arg);
}

void	ft_cd_1(t_data_mini *data)
{
	printf("cd: %s: No such file or directory\n", data->list_cmd->list_token[1]);
	data->dollar = 1;
}

void	ft_cd(t_data_mini *data)
{
	char	*new_path;
	char	*pwd;
	int		ret;

	if (data->list_cmd->list_token[1]
		&& data->list_cmd->list_token[1][0] == '~')
		manage_tilde(data);
	if (data->list_cmd->list_token[1])
	{
		ret = chdir(data->list_cmd->list_token[1]);
		if (ret == -1)
		{
			ft_cd_1(data);
			return ;
		}
		data->dollar = 0;
		pwd = getcwd(NULL, 0);
		new_path = ft_strjoin("PWD=", pwd);
		ft_export_var(data, new_path);
		free(new_path);
		free(pwd);
		return ;
	}
	ft_cd_bis(data);
}
