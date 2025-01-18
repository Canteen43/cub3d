/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/18 18:17:50 by kweihman         ###   ########.fr       */
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
// For f_gc_malloc(main, ), free()
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

# define MINIMAP 0

# define WIDTH 1280
# define HEIGHT 720

# define PI 3.14159265359
# define SPEED 0.1
# define ANGLE_SPEED 0.005
# define BLOCK 32

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
}						t_line_type;

// Garbage collection struct
typedef struct s_gnode
{
	void				*ptr;
	struct s_gnode		*next;
}						t_gnode;

// Main struct
typedef struct s_main
{
	t_gnode				*gc_head;
	char				*no_txtr_path;
	char				*ea_txtr_path;
	char				*so_txtr_path;
	char				*we_txtr_path;
	int					floor_color;
	int					ceiling_color;
	char				*entire_cubfile;
	char				**cubfile_line_by_line;
	int					cubfile_fd;
	int					map_line_count;
	int					map_line_width;
	float				player_x;
	float				player_y;
	char				direction;
	char				**map;
}						t_main;

// MLX struct
typedef struct s_player
{
	float				x;
	float				y;
	float				angle;

	bool				key_up;
	bool				key_right;
	bool				key_left;
	bool				key_down;

	bool				left_rotate;
	bool				right_rotate;
	t_main				*main;
}						t_player;

typedef struct s_main	t_main;

typedef struct s_game
{
	t_player			player;
	void				*mlx;
	void				*win;
	void				*img;

	char				*data;
	int					bpp;
	int					size_line;
	int					endian;

	t_main				*main;

}						t_game;

// Function declarations
// Utils
void					f_bzero(void *s, size_t n);
char					*f_readfile(t_main *main, int fd);
int						f_strcmp(char *str1, char *str2);
char					*f_strjoin(t_main *main, char const *s1,
							char const *s2);
size_t					f_strlen(const char *s);
int						f_char_count(char *str, char c);
char					*f_strchr(const char *s, int c);
void					*f_memcpy(void *dest, const void *src, size_t n);
char					**f_splitlines(t_main *main, char *text);
char					**f_split(t_main *main, char const *s, char c);
char					*f_strscmp(char *str1, int n, ...);
char					*f_strdup(t_main *main, const char *s);
bool					f_is_dig(char c);

// Parsing
bool					f_is_map_line(char *str);
void					f_set_color_config(t_main *main, t_line_type type,
							char *line);
bool					f_is_config_complete(t_main *main);
void					f_check_args(t_main *main, int argc, char **argv);
void					f_set_config_data(t_main *main);
t_line_type				f_set_input_line_type(t_main *main, char *line);
void					f_handle_cub_file(t_main *main, char **argv);
void					f_set_map(t_main *main);
void					f_check_for_invalid_map_lines(t_main *main);
void					f_set_map_dimensions(t_main *main);
void					f_create_map_array(t_main *main);
void					f_fill_map_array(t_main *main);
void					f_check_open_walls(t_main *main);
void					f_check_single_starting_pos(t_main *main);
void					f_import_cub_file(t_main *main, char **argv);
void					f_set_texture_path(t_main *main, t_line_type type,
							char *line);
void					f_extract_player_pos(t_main *main);

// Core
void					f_print_error(const char *func, char *message);
void					*f_gc_malloc(t_main *main, size_t size);
void					f_gc_clean(t_main *main);
void					f_graceful_exit(t_main *main, int exit_code,
							const char *func, char *message);
void					f_init(t_main *main);

// Debug
void					f_print_map(t_main *main);

// Rendering
void					f_init_player(t_game *game, t_player *player);
void					f_init_game(t_game *game, t_main *main);
void					f_draw_square(int x, int y, int size, int color,
							t_game *game);
int						f_key_press(int keycode, t_player *player);
int						f_key_release(int keycode, t_player *player);
void					f_move_player(t_player *player);
void					f_clear_image(t_game *game);
void					f_draw_minimap(t_game *game);
bool					f_touch(float px, float py, t_game *game);
float					f_distance(float x, float y);
float					f_fixed_dist(float x1, float y1, float x2, float y2,
							t_game *game);
void					f_draw_walls(float ray_x, float ray_y, t_player *player,
							t_game *game, int i);
void					f_draw_line(t_player *player, t_game *game,
							float start_x, int i);
int						f_draw_loop(t_game *game);
void					f_put_pixel(int x, int y, int color, t_game *game);
int						f_handle_close_button(void *param);
void					f_draw_full_square(int x, int y, int size, int color,
							t_game *game);

#endif // CUB3D_H
