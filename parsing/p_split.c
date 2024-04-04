#include "../minishell.h"

char	*skeep_qotes(char	*str, char c)
{
	str++;
	while (*str != c && *str)
		str++;
	return (str);
}

static int	count(const char	*str)
{
	int		nb_word;
	int		top;

	top = 0;
	nb_word = 0;
	while (*str)
	{
		while (*str == ' ' && *str)
			str++;
		while (*str != ' ' && *str)
		{
			top = 1;
			if ((*str == '\'' || *str == '\"') && *str)
				str = skeep_qotes((char *)str, *str);
			str++;
		}
		if (top == 1)
			nb_word++;
		top = 0;
	}
	return (nb_word);
}

static char	*perword(const char *str, int debut, int fin)
{
	char	*word;
	int		i;

	i = 0;
	word = (char *)malloc((fin - debut + 1));
	while (debut < fin)
		word[i++] = str[debut++];
	word[i] = '\0';
	return (word);
}

int	get_fin(char *str, int debut)
{
	while (str[debut] != ' ' && str[debut])
	{
		if (str[debut] == '\'' && str[debut])
		{
			debut++;
			while (str[debut] != '\'' && str[debut])
				debut++;
		}
		if (str[debut] == '\"' && str[debut])
		{
			debut++;
			while (str[debut] != '\"' && str[debut])
				debut++;
		}
		debut++;
	}
	return (debut);
}

char	**ft_split(const char	*s)
{
	int		i;
	int		nb_word;
	char	**split;
	int		debut;
	int		fin;

	debut = 0;
	fin = 0;
	nb_word = count(s);
	if (s)
		split = malloc((nb_word + 1) * sizeof(char *));
	if (!s || !split)
		return (0);
	i = 0;
	while (i < nb_word)
	{
		while (s[debut] == ' ')
			debut++;
		fin = get_fin((char *)s, debut);
		split[i] = perword(s, debut, fin);
		debut = fin;
		i++;
	}
	split[i] = 0;
	return (split);
}
