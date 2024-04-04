#include"../minishell.h"

char	*rl_gets(char *prompt)
{
	static char	*line_read = (char *) NULL;

	if (line_read)
	{
		free(line_read);
		line_read = (char *) NULL;
	}
	termios(0);
	line_read = readline(prompt);
	termios(1);
	return (line_read);
}

char	*rl_gets_init(t_data_mini *data)
{
	static char	*line_read = (char *) NULL;

	if (line_read)
	{
		free(line_read);
		line_read = (char *) NULL;
	}
	termios(0);
	line_read = readline(data->prompt);
	termios(1);
	if (line_read && *line_read != '\0')
	{
		data->cmd = line_read;
		run_shell(data);
	}
	return (line_read);
}

void	close_all_pipe(t_cmd *cmd, int i)
{
	int		p;
	t_cmd	*current;

	p = 0;
	current = cmd;
	while (p <= i)
	{
		close(current->fd[1]);
		close(current->fd[0]);
		current = current->before;
		p++;
	}
}

void	ft_open_close_pipe(t_cmd *cmd, int i, int nb_cmd)
{
	if (nb_cmd == 1)
		close_all_pipe(cmd, i);
	if (i == 0 && nb_cmd != 1)
	{
		dup2(cmd->fd[1], 1);
		close_all_pipe(cmd, i);
	}
	else if (i == nb_cmd - 1)
	{
		dup2(cmd->before->fd[0], 0);
		close_all_pipe(cmd, i);
	}
	else if (nb_cmd != 1)
	{
		dup2(cmd->before->fd[0], 0);
		dup2(cmd->fd[1], 1);
		close_all_pipe(cmd, i);
	}
}

void	ft_run_pipe(t_data_mini *data, int i)
{
	if (data->list_cmd->top_redir == 1)
		ft_open_close_pipe_red(data->list_cmd, i, data->nb_cmd);
	else
		ft_open_close_pipe(data->list_cmd, i, data->nb_cmd);
	if (ft_is_builtin_2(data->list_cmd->list_token[0]) == 1)
		ft_run_builtin_2(data);
	else if (data->list_cmd->top_redir == 1)
		execve(data->list_cmd->cmd_path, \
		(char *const *)data->list_cmd->cmd_redir, data->env);
	else
		execve(data->list_cmd->cmd_path, \
		(char *const *)data->list_cmd->list_token, data->env);
	exit(1);
}
