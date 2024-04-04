#include"../minishell.h"

void	lexer(t_data_mini *data)
{
	add_space_pipe(data);
	add_space_redir(data);
	data->list_token = ft_split(data->cmd);
	free(data->cmd);
}
