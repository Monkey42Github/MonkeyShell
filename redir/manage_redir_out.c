#include "../minishell.h"

int	is_redir(char **list_token)
{
	int	i;

	i = 0;
	while (list_token[i])
	{
		if (ft_strcmp(list_token[i], "<") == 0
			|| ft_strcmp (list_token[i], "<<") == 0
			|| ft_strcmp(list_token[i], ">") == 0
			|| ft_strcmp(list_token[i], ">>") == 0)
			return (1);
		i++;
	}
	return (0);
}

int	is_redir_char(char *list_token)
{
	if (ft_strcmp(list_token, "<") == 0
		|| ft_strcmp (list_token, "<<") == 0
		|| ft_strcmp(list_token, ">") == 0
		|| ft_strcmp(list_token, ">>") == 0)
		return (1);
	return (0);
}

char	**get_cmd_redir(char **list_token)
{
	int		nb_arg;
	int		i;
	char	**new_cmd;

	nb_arg = 0;
	while (list_token[nb_arg])
			nb_arg++;
	new_cmd = malloc((nb_arg + 1) * sizeof(char *));
	i = 0;
	nb_arg = 0;
	while (list_token[i])
	{
		if (is_redir_char(list_token[i]))
			i = i + 2;
		else
		{
			new_cmd[nb_arg] = list_token[i];
			nb_arg++;
			i++;
		}
	}
	new_cmd[nb_arg] = 0;
	return (new_cmd);
}

void	manage_redir_out_2(t_cmd *cmd, char *last_type_redir,
	char *last_file, int fd)
{
	if (ft_strcmp(last_type_redir, ">") == 0)
	{
		fd = open(last_file, O_WRONLY | O_TRUNC);
		cmd->fd_out = fd;
	}
	else
	{
		fd = open(last_file, O_WRONLY | O_APPEND);
		cmd->fd_out = fd;
	}
}

void	manage_redir_out(t_cmd *cmd)
{
	int		i;
	int		fd;
	char	*last_file;
	char	*last_type_redir;

	i = 0;
	while (cmd->list_token[i])
	{
		if (ft_strcmp(cmd->list_token[i], ">") == 0
			|| ft_strcmp(cmd->list_token[i], ">>") == 0)
		{
			last_file = cmd->list_token[i + 1];
			last_type_redir = cmd->list_token[i];
			fd = open(last_file, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
			i++;
			close(fd);
			cmd->redir_out = 1;
		}
		i++;
	}
	if (cmd->redir_out == 1)
		manage_redir_out_2(cmd, last_type_redir, last_file, fd);
}
