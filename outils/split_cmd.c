#include "../minishell.h"

char	**get_token_cmd(char **list_token, int *i)
{
	char	**token_cmd;
	int		nb_token;
	int		a;
	int		j;

	j = 0;
	nb_token = 0;
	a = *i;
	while (list_token[*i] && (ft_strcmp(list_token[*i], "|") != 0))
	{
		*i = *i + 1;
		nb_token++;
	}
	token_cmd = malloc((nb_token + 1) * sizeof(char *));
	*i = a;
	while (list_token[*i] && (ft_strcmp(list_token[*i], "|") != 0))
	{
		token_cmd[j] = list_token[*i];
		*i = *i + 1;
		j++;
	}
	*i = *i + 1;
	token_cmd[j] = 0;
	return (token_cmd);
}

t_cmd	*ft_new_cmd(char **list_token, int *idx, int num_cmd)
{
	t_cmd	*new;

	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->list_token = get_token_cmd(list_token, idx);
	new->num_cmd = num_cmd;
	new->nb_token = ft_len_tab(new->list_token);
	return (new);
}

int	get_nb_cmd(char **token_cmd)
{
	int	nb;
	int	i;

	i = 0;
	nb = 0;
	while (token_cmd[i])
	{
		if (ft_strcmp(token_cmd[i], "|") == 0)
			nb++;
		i++;
	}
	return (nb + 1);
}

void	init_back_node(t_cmd *first, int nb_cmd)
{
	t_cmd	*current;
	t_cmd	*next;
	int		i;

	i = 0;
	current = first;
	next = current->next;
	while (i < nb_cmd)
	{
		next->before = current;
		current = next;
		next = next->next;
		i++;
	}
}

t_cmd	*init_all_cmd(int nb_cmd, char **token_cmd)
{
	int		i;
	t_cmd	*first;
	t_cmd	*new;
	t_cmd	*current;
	int		idx;

	idx = 0;
	first = ft_new_cmd(token_cmd, &idx, 1);
	current = first;
	i = 2;
	while (i <= nb_cmd)
	{
		new = ft_new_cmd(token_cmd, &idx, i);
		current->next = new;
		current = new;
		i++;
	}
	current->next = first;
	init_back_node(first, nb_cmd);
	return (first);
}
