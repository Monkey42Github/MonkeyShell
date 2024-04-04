#include "../minishell.h"

int	ft_is_builtin_1(char *cmd)
{
	if (ft_strcmp(cmd, "cd") == 0 || ft_strcmp(cmd, "CD") == 0)
		return (1);
	if (ft_strcmp(cmd, "export") == 0 || ft_strcmp(cmd, "EXPORT") == 0)
		return (1);
	if (ft_strcmp(cmd, "unset") == 0 || ft_strcmp(cmd, "UNSET") == 0)
		return (1);
	if (ft_strcmp(cmd, "exit") == 0 || ft_strcmp(cmd, "EXIT") == 0)
		return (1);
	return (0);
}

int	ft_is_builtin_2(char *cmd)
{
	if (ft_strcmp(cmd, "echo") == 0 || ft_strcmp(cmd, "ECHO") == 0)
		return (1);
	if (ft_strcmp(cmd, "pwd") == 0 || ft_strcmp(cmd, "PWD") == 0)
		return (1);
	if (ft_strcmp(cmd, "env") == 0 || ft_strcmp(cmd, "ENV") == 0)
		return (1);
	return (0);
}

int	ft_run_builtin_1(t_data_mini *data)
{
	if (ft_strcmp(data->list_cmd->list_token[0], "cd") == 0
		|| ft_strcmp(data->list_cmd->list_token[0], "CD") == 0)
		ft_cd(data);
	if (ft_strcmp(data->list_cmd->list_token[0], "export") == 0
		|| ft_strcmp(data->list_cmd->list_token[0], "EXPORT") == 0)
		ft_export(data);
	if (ft_strcmp(data->list_cmd->list_token[0], "unset") == 0
		|| ft_strcmp(data->list_cmd->list_token[0], "UNSET") == 0)
		ft_unset(data);
	if (ft_strcmp(data->list_cmd->list_token[0], "exit") == 0
		|| ft_strcmp(data->list_cmd->list_token[0], "EXIT") == 0)
		ft_exit(data);
	return (1);
}

int	ft_run_builtin_2(t_data_mini *data)
{
	if (ft_strcmp(data->list_cmd->list_token[0], "echo") == 0
		|| ft_strcmp(data->list_cmd->list_token[0], "ECHO") == 0)
		ft_echo(data);
	if (ft_strcmp(data->list_cmd->list_token[0], "pwd") == 0
		|| ft_strcmp(data->list_cmd->list_token[0], "PWD") == 0)
		ft_pwd(data);
	if (ft_strcmp(data->list_cmd->list_token[0], "env") == 0
		|| ft_strcmp(data->list_cmd->list_token[0], "ENV") == 0)
		ft_env(data);
	return (1);
}
