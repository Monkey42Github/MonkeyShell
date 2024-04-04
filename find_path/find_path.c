#include "../minishell.h"

int	count_words_1(char *str, char c)
{
	int	i;
	int	trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup_1(char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split_1(char *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;

	split = malloc((count_words_1(s, c) + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == strlen(s)) && index >= 0)
		{
			split[j++] = word_dup_1(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

char	**ft_test_1(char **env)
{
	char	*path;
	char	**path2;
	int		i;
	int		j;
	int		a;

	a = 0;
	j = 0;
	i = 0;
	while (env[i++])
	{
		if (env[i][0] == 'P' && env[i][1] == 'A' && env[i][2] == 'T'\
		&& env[i][3] == 'H' && env[i][4] == '=')
		{
			j = strlen(env[i]) - 5;
			path = malloc(sizeof(char) * j +1);
			j = 5;
			while (env[i][j++])
				path[a++] = env[i][j];
			path2 = ft_split_1(path, ':');
			free(path);
			return (path2);
		}
	}
	return (NULL);
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
