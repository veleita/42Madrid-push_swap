#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

# include <common.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 60
# endif

int	get_next_line(int fd, char **line);

#endif
