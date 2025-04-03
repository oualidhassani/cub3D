/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenaiss <ibenaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:04:19 by ibenaiss          #+#    #+#             */
/*   Updated: 2025/01/27 15:07:23 by ibenaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_H
# define LIB_H

# include "libft/libft.h"
# include "mlx.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# define FLT_MAX 3.402823466e+38F
# define RED 0x00FF0000
# define GREEN 0x0000FF00
# define BLUE 0x000000FF
# define TILE_SIZE 64
# define WINDOW_WIDTH 860
# define WINDOW_HEIGHT 720
# define EPSILON 0.0001
# define M_PI 3.14159265358979323846
# define NORTH_FACE 0
# define SOUTH_FACE 1
# define EAST_FACE 2
# define WEST_FACE 3
# define NORTH_WALL_COLOR 0xCC0000
# define SOUTH_WALL_COLOR 0x00CC00
# define EAST_WALL_COLOR 0x0000CC
# define WEST_WALL_COLOR 0xCCCC00

typedef struct s_pos
{
	double			x;
	double			y;
}					t_pos;

typedef struct s_ray_calc
{
	float			ray_dir_x;
	float			ray_dir_y;
	float			pos_x;
	float			pos_y;
	int				map_x;
	int				map_y;
	float			delta_dist_x;
	float			delta_dist_y;
	int				step_x;
	int				step_y;
	float			side_dist_x;
	float			side_dist_y;
}					t_ray_calc;

typedef struct s_texture_map
{
	char			*identifier;
	int				face_index;
}					t_texture_map;

typedef struct s_texture
{
	char			*addr;
	int				len;
	int				bpp;
}					t_texture;

typedef struct s_tex
{
	char			*tex_path;
	uint32_t		*texture;
	int				width;
	int				height;
	char			*addr;
	int				len;
	int				bpp;
}					t_tex;

typedef struct s_wall_data
{
	int				strip_height;
	int				top_pixel;
	int				bottom_pixel;
	float			perp_distance;
	float			proj_plane;
	float			proj_height;
	float			tex_x;
	float			tex_pos;
	float			step;
}					t_wall_data;

typedef struct s_ray
{
	int				id;
	float			ray_angle;
	float			wall_hit_x;
	float			wall_hit_y;
	int				horizontal_wall_content;
	int				vertical_wall_content;
	float			horizontal_wall_hit_x;
	float			horizontal_wall_hit_y;
	float			vertical_wall_hit_x;
	float			vertical_wall_hit_y;
	bool			was_hit_vertical;
	bool			was_hit_horizontal;
	float			vertical_distance;
	float			distance;
	float			horizontal_distance;
	int				is_ray_facing_up;
	int				is_ray_facing_down;
	int				is_ray_facing_right;
	int				is_ray_facing_left;
	int				wall_hit_content;
	float			next_vertical_touch_x;
	float			next_vertical_touch_y;
	float			next_horizontal_touch_x;
	float			next_horizontal_touch_y;
	int				wall_face;
	double			wall_x;
	int				tex_x;
	int				line_height;
	double			perp_wall_dist;
}					t_ray;

typedef struct s_player
{
	char			starting_face_in_map;
	float			p_x;
	float			p_y;
	float			size;
	int				dir;
	float			radius;
	float			turn_direction;
	float			walk_direction;
	float			strafe_direction;
	float			rotation_angle;
	float			move_speed;
	float			rotation_speed;
	float			fov;
	float			wall_strip_width;
	float			wall_strip_height;
	int				number_of_rays;
	float			start_column_angle;
	t_ray			*rays;
}					t_player;

typedef struct s_rgb
{
	int				r;
	int				g;
	int				b;
}					t_rgb;

typedef struct s_img
{
	void			*img;
	int				img_width;
	int				img_height;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_map
{
	char			*no_texture;
	char			*so_texture;
	char			*we_texture;
	char			*ea_texture;
	char			*floor_color;
	char			*ceiling_color;
	char			**map;
	int				height;
	int				width;
	int				td_map_size;
	struct s_player	player;
	struct s_rgb	floor_rgb;
	struct s_rgb	ceiling_rgb;
}					t_map;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	t_img			img;
	t_map			maps;
	t_tex			tex[4];
	t_player		player;
}					t_mlx;

void				player_position(t_mlx *mlx);
void				init_player(t_mlx *mlx);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
void				update_player(t_mlx *mlx);
void				player_center_position(t_mlx *mlx, int x, int y);
void				render_3d_projection_walls(t_mlx *mlx);
void				render_all(t_mlx *mlx);
int					close_window(void *mlx_ptr);
void				free_rays(t_mlx *mlx);
void				my_mlx_pixel_put(t_img *img, int x, int y, int color);
int					mlx_initializer(t_mlx *mlx);
void				draw_wall(t_mlx *mlx, int x, int y);
void				start_parsing(char *av, t_map *map);
void				map_initializer(t_map *map);
void				error_print(char *str, t_map *map);
void				file_parser(int fd, t_map *map);
void				parse_textures(t_map *map);
void				save_textures(char *line, t_map *map);
void				map_parser(int fd, t_map *map);
void				parse_colors(t_map *map);
bool				check_file_extension(char *av);
void				free2d(char **str);
bool				ft_isspace(char c);
char				*ft_substr_plus(char *s);
bool				is_all_whitespace(char *str);
bool				check_newline(char *map);
bool				check_comma(char *str);
bool				check_rgb(t_rgb rgb);
void				parse_rgb(t_map *map);
bool				check_map(char *map);
void				draw_ceiling(t_mlx *mlx, int top_pixel, int ray_index);
void				reset_movement_flags(t_mlx *mlx);
void				update_position(t_mlx *mlx, float move_step,
						float strafe_step);
void				save_current_position(t_mlx *mlx, int *old_x, int *old_y);
void				draw_floor(t_mlx *mlx, int bottom_pixel, int ray_index);
long				ft_atomic_atoi(char *str);
bool				check_path(char *path);
void				save_colors(char *line, t_map *map);
void				save_player(t_map *map);
void				verify_textures(const char *texture_paths[4]);
int					verify_texture_dimensions(t_mlx *mlx, t_img *img,
						const char *path);
void				cleanup_textures(t_mlx *mlx);
void				init_check_points(float check_points[8][2]);
void				cleanup_mlx(t_mlx *mlx);
void				cleanup_map(t_map *map);
void				load_texture(t_mlx *mlx);
int					key_release(int key_code, void *mlx_ptr);
void				refreshing(t_mlx *mlx);
void				draw_scene(t_mlx *mlx);
uint32_t			apply_shade(uint32_t color, float shade);
uint32_t			get_shaded_color(t_tex *texture, float perp_distance,
						int tex_x, int tex_y);
int					key_press(int key_code, void *mlx_ptr);
int					handle_exit(t_mlx *mlx);
void				init_texture_paths(t_mlx *mlx,
						const char *texture_paths[4]);
float				normalize_angle(float angle);
void				ray(t_mlx *mlx, t_ray *ray);
void				ray_init(t_mlx *mlx);
void				init_ray_steps(float pos_x, float pos_y, t_ray_calc *calc);
void				set_starting_direction(t_mlx *mlx);
void				init_player(t_mlx *mlx);
int					does_hit_right_bottom_wall(t_mlx *mlx, int x, int y);
int					does_hit_left_top_wall(t_mlx *mlx, int x, int y);
void				update_player(t_mlx *mlx);
float				calculate_perp_distance(t_ray *ray, float player_angle);
void				render_3d_projection_walls(t_mlx *mlx);
void				cast(t_mlx *mlx, t_ray *ray);
void				adjusting_rays(t_mlx *mlx);
int					ft_str2dlen(char **str);
char				*ft_strjoin_gnl(char *s1, char *s2);

#endif