#include "cub3D.h"

void	ft_free2darray(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	loop_map(t_thegame *data, int fd)
{
	char	*joiner;
	char	*buffer;

	joiner = NULL;
	while (1)
	{
		buffer = get_next_line(fd);
		if (buffer == NULL)
			break ;
		if (buffer[0] == '\n')
			print_errors("Error there is a newline on the map");
		joiner = ft_strjoin(joiner, buffer);
		data->height++;
		free(buffer);
	}
	if (!joiner)
		print_errors("Error map empty");
	if (joiner[ft_strlen(joiner) - 1] == '\n')
	{
		close(fd);
		free(joiner);
		print_errors("Error there is a newline on the map");
	}
	data->map = ft_split(joiner, '\n');
	free(joiner);
}

int stocking_on_the_map(t_thegame *data, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		print_errors("fail the file\n");
	data->height = 0;
	loop_map(data, fd);
	if (data->map == NULL)
	{
		close(fd);
		ft_free2darray(data->map);
		print_errors("failed malloc\n");
	}
	if (data->height == 0)
	{
		close(fd);
		return (1);
	}
	data->map[data->height] = 0;
	data->width = ft_strlen(data->map[0]);
	close(fd);
	return (0);
}
