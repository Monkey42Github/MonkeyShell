#include "../minishell.h"

char	*ft_strjoin_3(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, s2);
	res = ft_strjoin(tmp, s3);
	free(tmp);
	return (res);
}

char	*get_cmd_path(char **env, char	*cmd)
{
	char		**ev;
	char		*path;
	int			i;
	struct stat	sb;

	i = 0;
	ev = ft_test_1(env);
	while (ev[i])
	{
		path = ft_strjoin_3(ev[i], "/", cmd);
		if (stat(path, &sb) == 0 && S_ISREG(sb.st_mode)
			&& (sb.st_mode & S_IXUSR))
		{
			ft_free_tab(ev);
			return (path);
		}
		i++;
		free(path);
	}
	ft_free_tab(ev);
	return (NULL);
}

char	*check_abs_path(char *str)
{
	char		**chemin;
	int			i;
	struct stat	sb;

	i = 0;
	chemin = ft_split_1(str, '/');
	while (chemin[i])
		i++;
	if (ft_is_builtin_1(chemin[i - 1]) == 1 || ft_is_builtin_2(chemin[i - 1]))
	{
		ft_free_tab(chemin);
		return (NULL);
	}
	ft_free_tab(chemin);
	if (stat(str, &sb) == 0 && S_ISREG(sb.st_mode) && (sb.st_mode & S_IXUSR))
	{
		return (str);
	}
	return (NULL);
}

void	ft_find_path_2(t_data_mini *data, char *token_cmd)
{
	if (ft_strchr(token_cmd, '/'))
	{
		data->list_cmd->cmd_path = \
		check_abs_path(token_cmd);
		data->list_cmd->top_path = 0;
	}
	else if (did_var_exist(data, "PATH") == 0)
	{
		data->list_cmd->top_path = 0;
		data->list_cmd->cmd_path = NULL;
	}
	else
	{
		data->list_cmd->cmd_path = get_cmd_path(data->env, \
		token_cmd);
		data->list_cmd->top_path = 1;
	}
}

int	ft_find_path(t_data_mini *data)
{
	int		i;
	char	*token_cmd;

	i = 0;
	while (i++ < data->nb_cmd)
	{
		if (data->list_cmd->top_redir == 1)
			token_cmd = data->list_cmd->cmd_redir[0];
		else
			token_cmd = data->list_cmd->list_token[0];
		if (!token_cmd)
			return (0);
		ft_find_path_2(data, token_cmd);
		if (data->list_cmd->cmd_path == NULL
			&& ft_is_builtin_1(token_cmd) != 1
			&& ft_is_builtin_2(token_cmd) != 1)
		{
			printf("command not found %s\n", token_cmd);
			data->dollar = 127;
			return (0);
		}
		data->list_cmd = data->list_cmd->next;
	}
	return (1);
}
