/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 18:25:04 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

// For open(), close()
# include <fcntl.h>
// For read(), write()
# include <unistd.h>
// For printf()
# include <stdio.h>
// For f_gc_malloc(game, ), free()
# include <stdlib.h>
// For perror(), strerror()
# include <string.h>
// For exit()
# include <stdlib.h>
// For gettimeofday()
# include <sys/time.h>
// For booleans
# include <stdbool.h>
// For MLX
# include "mlx.h"
// For sin and cos
# include <math.h>
// For keycodes
# include <X11/keysym.h>
// For color macros
# include "colors.h"

// Macros
# define BUFFER_SIZE 256

# define WIDTH 1280
# define HEIGHT 720

# define PI 3.14159265359
# define SPEED 0.1
# define ANGLE_SPEED 0.02
# define MINIBLOCK 16
# define FRAMES_PER_SECOND 80

// Coordinate struct
typedef struct s_coordinates
{
	float			x;
	float			y;
}					t_coords;

// Circle struct
typedef struct s_circle
{
	int				color;
	float			radius;
	t_coords		center;
}					t_circle;

// Square struct
typedef struct s_square
{
	int				color;
	float			size;
	t_coords		top_left;
}					t_square;

// Texture struct
typedef struct s_texture
{
	char			*path;
	void			*img_ptr;
	int				width;
	int				height;
}					t_tex;

// Line type enum
typedef enum e_line_type
{
	EMPTY,
	NORTH,
	EAST,
	SOUTH,
	WEST,
	FLOOR,
	CEILING,
	MAP,
	WRONG,
}					t_line_type;

// Garbage collection struct
typedef struct s_gnode
{
	void			*ptr;
	struct s_gnode	*next;
}					t_gnode;

// Main struct
typedef struct s_game
{
	t_gnode			*gc_head;
	t_tex			north;
	t_tex			east;
	t_tex			south;
	t_tex			west;
	int				floor_color;
	int				ceiling_color;
	char			*entire_cubfile;
	char			**cubfile_line_by_line;
	int				cubfile_fd;
	int				map_line_count;
	int				map_line_width;
	char			**map;
	void			*mlx;
	void			*win;
	void			*img;

	char			*data;
	int				bpp;
	int				size_line;
	int				endian;

	bool			key_up;
	bool			key_right;
	bool			key_left;
	bool			key_down;
	bool			left_rotate;
	bool			right_rotate;

	float			player_angle;
	t_coords		player_pos;
	t_coords		grid_hit;
	t_coords		wall_hit;
}					t_game;

// Function declarations
// Utils
void				f_bzero(void *s, size_t n);
char				*f_readfile(t_game *game, int fd);
int					f_strcmp(char *str1, char *str2);
char				*f_strjoin(t_game *game, char const *s1, char const *s2);
size_t				f_strlen(const char *s);
int					f_char_count(char *str, char c);
char				*f_strchr(const char *s, int c);
void				*f_memcpy(void *dest, const void *src, size_t n);
char				**f_splitlines(t_game *game, char *text);
char				**f_split(t_game *game, char const *s, char c);
char				*f_strscmp(char *str1, int n, ...);
char				*f_strdup(t_game *game, const char *s);
bool				f_is_dig(char c);

// Parsing
bool				f_is_map_line(char *str);
void				f_set_color_config(t_game *game, t_line_type type,
						char *line);
bool				f_is_config_complete(t_game *game);
void				f_check_args(t_game *game, int argc, char **argv);
void				f_set_config_data(t_game *game);
t_line_type			f_set_input_line_type(t_game *game, char *line);
void				f_handle_cub_file(t_game *game, char **argv);
void				f_set_map(t_game *game);
void				f_check_for_invalid_map_lines(t_game *game);
void				f_set_map_dimensions(t_game *game);
void				f_create_map_array(t_game *game);
void				f_fill_map_array(t_game *game);
void				f_check_open_walls(t_game *game);
void				f_check_single_starting_pos(t_game *game);
void				f_import_cub_file(t_game *game, char **argv);
void				f_set_texture_path(t_game *game, t_line_type type,
						char *line);
void				f_extract_game_pos(t_game *game);

// Core
void				f_print_error(const char *func, char *message);
void				*f_gc_malloc(t_game *game, size_t size);
void				f_gc_clean(t_game *game);
void				f_graceful_exit(t_game *game, int exit_code,
						const char *func, char *message);
void				f_init(t_game *game);

// Debug
void				f_print_map(t_game *game);
void				f_debug_info(t_game *game);

// Rendering
void				f_start_mlx(t_game *game);
void				f_start_mlx(t_game *game);
void				f_draw_square(t_game *game, t_square sq);
int					f_key_press(int keycode, t_game *game);
int					f_key_release(int keycode, t_game *game);
void				f_move_player(t_game *game);
void				f_clear_image(t_game *game);
void				f_draw_minimap(t_game *game);
bool				f_touch(float px, float py, t_game *game);
void				f_draw_walls(float ray_x, float ray_y, t_game *game, int i);
void				f_draw_line(t_game *game, float start_x, int i);
int					f_game_loop(t_game *game);
void				f_put_pixel(int x, int y, int color, t_game *game);
int					f_handle_close_button(void *param);
void				f_draw_full_square(t_game *game, t_square sq);
void				f_draw_circle_full(t_game *game, t_circle circle);
float				f_distance(t_coords p1, t_coords p2);
void				f_attempt_move(t_game *game, char dimension,
						float distance);
float				f_find_target(float current, float vector);
t_coords			f_next_grid_hit(t_coords current, float angle);
bool				f_is_round(float nbr);
bool				f_is_wall(t_game *game, t_coords pos);
void				f_load_textures(t_game *game);
#endif // CUB3D_H
