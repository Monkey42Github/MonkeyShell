#include "minishell.h"

void	ft_clean_all(t_data_mini *data)
{
	t_cmd	*current;
	int		i;

	i = 0;
	ft_free_tab(data->list_token);
	while (i < data->nb_cmd - 1)
	{
		current = data->list_cmd;
		if (current->top_path == 1)
			free(current->cmd_path);
		free(current->list_token);
		if (current->top_redir)
			free(current->cmd_redir);
		free(current);
		data->list_cmd = data->list_cmd->next;
		i++;
	}
	if (data->list_cmd->top_path == 1)
		free(data->list_cmd->cmd_path);
	free(data->list_cmd->list_token);
	if (data->list_cmd->top_redir)
		free(data->list_cmd->cmd_redir);
	free(data->list_cmd);
	unlink(".tmp");
}

char	**manage_no_env(void)
{
	char	**new_env;
	char	*pwd;

	pwd = getcwd(NULL, 0);
	new_env = malloc(4 * sizeof(char *));
	new_env[0] = ft_strjoin("PWD=", pwd);
	free(pwd);
	new_env[1] = malloc((sizeof(char) * 8));
	ft_strcpy(new_env[1], "SHLVL=1");
	new_env[2] = malloc((sizeof(char) * 15));
	ft_strcpy(new_env[2], "_=/usr/bin/env");
	new_env[3] = 0;
	return (new_env);
}

char	**ft_init_env(char **env)
{
	char	**new_env;
	int		i;

	i = 0;
	while (env[i])
		i++;
	if (i == 0)
	{
		new_env = manage_no_env();
		return (new_env);
	}
	new_env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		new_env[i] = ft_strdup(env[i]);
		i++;
	}
	new_env[i] = 0;
	return (new_env);
}

int	main(int ac, char **av, char **env)
{	
	t_data_mini	data;

	(void)(av);
	(void)(ac);
	data.env = ft_init_env(env);
	data.dollar = 0;
	data.prompt = "MonkeyShell >> ";
	while (rl_gets_init(&data))
	{
		if (data.dollar >= 256)
			data.dollar = data.dollar / 256;
	}
	return (0);
}
