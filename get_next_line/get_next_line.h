#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

size_t		ft_strlen(const char *s);
char		*ft_strnew(int size);
char		*ft_strjoin(char *s1, char *s2);
int			get_next_line(**line);


#endif
