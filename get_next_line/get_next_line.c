#include "get_next_line.h"

size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		++i;
	return (i);
}

char		*ft_strnew(int size)
{
	char	*new;

	new = (char *)malloc(sizeof(char) * (size + 1));
	if (!new)
		return (NULL);
	new[size] = '\0';
	return (new);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	new = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		++i;
	}
	free(s1);
	while (s2[j] != '\0')
	{
		new[i] = s2[j];
		++i;
		++j;
	}
	new[i] = '\0';
	return (new);
}

int			get_next_line(char **line)
{
	char	*buf;
	int		n;

	buf = (char *)malloc(sizeof(char) * 2);
	n = 0;
	if (!line || (read(0, buf, 0)) < 0)
		return (-1);
	*line = ft_strnew(0);
	while ((n = read(0, buf, 1)))
	{
		if (buf[0] == '\n')
		{
			free(buf);
			return (1);
		}
		buf[n] = '\0';
		*line = ft_strjoin(*line, buf);
	}
	free(buf);
	return (0);
}
