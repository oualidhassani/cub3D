#include "cub3D.h"

// size_t ft_strlen(char *str)
// {
//     size_t i;
//     i = 0;

//     while(str[i])
//         i++;
//     return(i);

// }

int	ft_strcmp1(char *s1, char *s2)
{
	int	i;
	int	d;

	i = 0;
	d = 0;
	while ((s2[i] != '\0' && s1[i] != '\0'))
	{
		if (s1[i] != s2[i])
			d = s1[i] - s2[i];
		i++;
	}
	return (d);
}

void print_errors(char *str)
{
    write(2, str, ft_strlen(str));
}

void check_name(char **av)
{
    char *str;
    str = ".cub";

    size_t len;

    len = ft_strlen(av[1]);

    if(len >= 4)
    {
        if(ft_strcmp1(av[1] + len - 4 , str) != 0)
            print_errors("Error not ending with .cub\n");
    }
}

void    read_the_map(t_thegame *game, char *file)
{
    int fd;

    fd = open(file, O_RDONLY);

    char *buffer;

    if(fd == -1)
        print_errors("fail on the file descriptor");
    
    while(2)
    {
        buffer = get_next_line(fd);
        if(buffer == NULL)
            return ;
        game->height++;
        free(buffer);
        buffer = NULL;
    }
    close(fd);
}