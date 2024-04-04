#include "../minishell.h"

void	init_ft_command(pid_t *pid, int *i, int *fork_error)
{
	*i = 0;
	*pid = 1;
	*fork_error = 0;
}

void	printf_fork_error(int fork_error)
{
	if (fork_error == 1)
		printf("fork failed: resource temporarily unavailable\n");
}

void	ft_command(t_data_mini *data)
{
	pid_t	pid;
	int		i;
	int		fork_error;

	init_ft_command(&pid, &i, &fork_error);
	while (i < data->nb_cmd)
	{
		pipe(data->list_cmd->fd);
		if (ft_is_builtin_1(data->list_cmd->list_token[0]) == 1
			&& data->nb_cmd == 1)
			ft_run_builtin_1(data);
		else if (ft_is_builtin_1(data->list_cmd->list_token[0]) != 1)
			pid = fork();
		if (pid == 0)
			ft_run_pipe(data, i);
		else if (pid < 0)
			fork_error = 1;
		data->list_cmd = data->list_cmd->next;
		i++;
	}
	if (i != 1)
		close_all_pipe(data->list_cmd, i - 1);
	while (waitpid(0, &data->dollar, 0) != -1)
		;
	printf_fork_error(fork_error);
}

void	run_shell(t_data_mini *data)
{
	add_history(data->cmd);
	if (ft_parcing_readline(data) == 0)
		return ;
	data->nb_cmd = get_nb_cmd(data->list_token);
	if (data->cmd[0])
	{
		data->list_cmd = init_all_cmd(data->nb_cmd, data->list_token);
		ft_clean_quotes(data);
	}
	else
	{
		ft_free_tab(data->list_token);
		return ;
	}
	if (check_if_redir(data) == 0)
		return ;
	if (ft_find_path(data) == 1)
		ft_command(data);
	ft_clean_all(data);
}
