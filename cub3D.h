#ifndef cub3D_H
#define cub3D_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 1337
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "libft/libft.h"

typedef struct s_thegame
{
    char	**map;
    size_t  height;
    size_t  width;

} t_thegame;

// check the name
void    check_name(char **av);

// read the map
void    read_the_map(t_thegame *game, char *file);
char	*get_next_line(int fd);
int	stocking_on_the_map(t_thegame *data, char *file);

// error functions 
void    print_errors(char *str);

// the function for get_next_line
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*linesub(char *line_buffer);
char	*mybuffer(int fd, char *accumulation, char *buffer);

// free function 
void	ft_free2darray(char **str);

// utils function 

#endif