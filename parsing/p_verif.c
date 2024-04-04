#include"../minishell.h"

int	v_quote(char *str, char a, char b)
{
	char	*line;
	int		flag;
	char	*first;

	first = str;
	flag = 0;
	line = str;
	while (*line)
	{
		if (*line == a && flag == 0)
			flag = 1;
		else if (*line == a && flag == 1)
			flag = 0;
		if (*line == b && flag == 0)
		{
			line = ft_strchr(++line, b);
			if (!line)
				return (0);
		}
		line++;
	}
	str = first;
	return (1);
}

void	count_nb_redir(char *str)
{
	int	i;

	i = 0;
	while (str[i] == *str)
		i++;
	if (i % 2 == 0)
		printf("parse error near `%c%c'\n", (char)*str, (char)*str);
	else
		printf("parse error near `%c'\n", (char)*str);
}

int	verif_redir(char *cmd)
{
	char	q;
	char	*first;

	first = cmd;
	while (*cmd)
	{
		if (*cmd == '\'' || *cmd == '\"')
		{
			q = *cmd;
			cmd++;
			while (*cmd != q)
				cmd++;
		}
		if (*cmd == '<' || *cmd == '>' )
		{
			if (cmd[1] == *cmd && cmd[2] == *cmd && cmd[1] && cmd[2])
			{
				count_nb_redir(cmd);
				return (0);
			}
		}
		cmd++;
	}
	cmd = first;
	return (1);
}
