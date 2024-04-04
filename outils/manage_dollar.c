#include"../minishell.h"

void	init_tab_char_sp(int *tab)
{
	tab[0] = 32;
	tab[1] = 37;
	tab[2] = 43;
	tab[3] = 44;
	tab[4] = 46;
	tab[5] = 47;
	tab[6] = 58;
	tab[7] = 60;
	tab[8] = 61;
	tab[9] = 63;
	tab[10] = 64;
	tab[11] = 91;
	tab[12] = 92;
	tab[13] = 93;
	tab[14] = 94;
	tab[15] = 123;
	tab[16] = 124;
	tab[17] = 125;
	tab[18] = 126;
	tab[19] = '$';
	tab[20] = '\'';
	tab[21] = '\"';
}

int	check_is_special(char c)
{
	int	tab[22];
	int	i;

	init_tab_char_sp(tab);
	i = 0;
	while (tab[i])
	{
		if (tab[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*get_var(char *cmd, int *i)
{
	char	*var;
	int		len;
	int		ii;

	len = 0;
	ii = 0;
	while (!check_is_special(cmd[len + 1]) && cmd[len + 1])
		len++;
	*i = *i + len;
	var = malloc((len +1) * sizeof(char));
	while (ii < len)
	{
		var[ii] = cmd[ii + 1];
		ii++;
	}
	var[ii] = '\0';
	return (var);
}

char	*get_new_value(char *var, char **env)
{
	int	i;
	int	ii;

	i = 0;
	while (env[i])
	{
		ii = 0;
		while (var[ii] == env[i][ii])
		{
			if (env[i][ii + 1] == '=' && var[ii + 1] == '\0')
			{
				ii++;
				free(var);
				return (&env[i][ii + 1]);
			}
			ii++;
		}
		i++;
	}
	free(var);
	return (NULL);
}

char	*ft_strjoin_33(char *s1, char *s2, char *s3)
{
	char	*tmp;
	char	*res;

	tmp = ft_strjoin(s1, s2);
	res = ft_strjoin(tmp, s3);
	free(tmp);
	if (s1)
		free(s1);
	return (res);
}
