/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_v3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ohassani <ohassani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:50:28 by ohassani          #+#    #+#             */
/*   Updated: 2025/01/19 20:21:35 by ohassani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib.h"

void	parse_rgb(t_map *map)
{
	char	**split;
	int		i;

	split = ft_split(map->floor_color, ',');
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error_print("Invalid color format", map);
	map->floor_rgb.r = ft_atomic_atoi(split[0]);
	map->floor_rgb.g = ft_atomic_atoi(split[1]);
	map->floor_rgb.b = ft_atomic_atoi(split[2]);
	free2d(split);
	split = ft_split(map->ceiling_color, ',');
	i = 0;
	while (split[i])
		i++;
	if (i != 3)
		error_print("Invalid color format", map);
	map->ceiling_rgb.r = ft_atomic_atoi(split[0]);
	map->ceiling_rgb.g = ft_atomic_atoi(split[1]);
	map->ceiling_rgb.b = ft_atomic_atoi(split[2]);
	free2d(split);
}

void	parse_textures(t_map *map)
{
	map->no_texture = ft_substr_plus(map->no_texture);
	map->so_texture = ft_substr_plus(map->so_texture);
	map->we_texture = ft_substr_plus(map->we_texture);
	map->ea_texture = ft_substr_plus(map->ea_texture);
	if (!check_path(map->no_texture) || !check_path(map->so_texture)
		|| !check_path(map->we_texture) || !check_path(map->ea_texture))
		error_print("Invalid path", map);
}

void	file_parser(int fd, t_map *map)
{
	char	*line;
	char	*s;

	while (1)
	{
		s = get_next_line(fd);
		if (!s)
			break ;
		line = ft_strtrim(s, "\n");
		free(s);
		if (!line)
			break ;
		if (!map->no_texture || !map->so_texture || !map->we_texture
			|| !map->ea_texture)
			save_textures(line, map);
		else if (!map->floor_color || !map->ceiling_color)
			save_colors(line, map);
		free(line);
		if (map->no_texture && map->so_texture && map->we_texture
			&& map->ea_texture && map->floor_color && map->ceiling_color)
			break ;
	}
	if (!map->no_texture || !map->so_texture || !map->we_texture
		|| !map->ea_texture || !map->floor_color || !map->ceiling_color)
		error_print("Missing Textures/Color, or map empty", map);
}

void	process_map_dimensions(t_map *map)
{
	int	i;
	int	line_length;

	i = 0;
	map->height = 0;
	while (map->map[map->height])
		map->height++;
	map->width = 0;
	while (i < map->height)
	{
		line_length = ft_strlen(map->map[i]);
		if (line_length > map->width)
			map->width = line_length;
		i++;
	}
}

void	map_parser(int fd, t_map *map)
{
	char	*line;
	char	*map1d;

	map1d = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		map1d = ft_strjoin_gnl(map1d, line);
		free(line);
	}
	if (!check_map(map1d))
		error_print("Invalid map", map);
	map->map = ft_split(map1d, '\n');
	process_map_dimensions(map);
	save_player(map);
	free(map1d);
}
