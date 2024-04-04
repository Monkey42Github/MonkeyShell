#include"../minishell.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *) s;
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == (char)c)
		return (&str[i]);
	return (NULL);
}

char	*ft_strcat(char *s1, const char *s2)
{
	int	len;
	int	i;

	len = ft_strlen(s1);
	i = 0;
	while (s2[i])
		s1[len++] = ((char *)s2)[i++];
	s1[len] = '\0';
	return (s1);
}

char	*ft_strcpy(char *dst, const char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	size = 0;
	if (s1)
		size += ft_strlen(s1);
	if (s2)
		size += ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	if (s1 && s2)
	{
		ft_strcat(ft_strcpy(res, s1), s2);
		return (res);
	}
	else if (s1 != NULL && s2 == NULL)
		return (ft_strcpy(res, s1));
	else if (s1 == NULL && s2 != NULL)
		return (ft_strcpy(res, s2));
	else
		return (NULL);
}
