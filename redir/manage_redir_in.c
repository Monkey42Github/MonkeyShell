#include "../minishell.h"

void	ft_read_heredoc(char *stop_word, t_cmd *cmd)
{
	char	*line;
	int		fd;

	fd = open(".tmp", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR);
	line = rl_gets("heredoc>");
	while (ft_strcmp(line, stop_word) != 0)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		line = rl_gets("heredoc>");
	}
	close(fd);
	cmd->fd_in = open(".tmp", O_RDONLY);
	cmd->redir_in = 1;
}

void	manage_redir_in_2(t_cmd *cmd, int *err, char **err_file, int i)
{
	cmd->fd_in = open(cmd->list_token[i], O_RDONLY);
	cmd->redir_in = 1;
	if (cmd->fd_in == -1)
	{
		*err = 1;
		*err_file = cmd->list_token[i];
	}
}

int	manage_redir_in(t_cmd *cmd)
{
	int		i;
	int		err;
	char	*err_file;

	i = 0;
	err = 0;
	while (cmd->list_token[i])
	{
		if (ft_strcmp(cmd->list_token[i], "<<") == 0)
			ft_read_heredoc(cmd->list_token[++i], cmd);
		if (ft_strcmp(cmd->list_token[i], "<") == 0 && err == 0)
			manage_redir_in_2(cmd, &err, &err_file, ++i);
		if (err == 1)
		{
			printf("file not foud %s\n", err_file);
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_if_redir(t_data_mini *data)
{
	int	i;

	i = 0;
	while (i < data->nb_cmd)
	{
		if (is_redir(data->list_cmd->list_token) == 1)
		{
			data->list_cmd->top_redir = 1;
			data->list_cmd->cmd_redir = \
				get_cmd_redir(data->list_cmd->list_token);
			manage_redir_out(data->list_cmd);
			if (manage_redir_in(data->list_cmd) == 0)
				return (0);
		}
		else
			data->list_cmd->top_redir = 0;
		data->list_cmd = data->list_cmd->next;
		i++;
	}
	return (1);
}
