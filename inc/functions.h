/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:31:19 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 14:19:50 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FUNCTIONS_H
# define FUNCTIONS_H

void		f_bzero(void *s, size_t n);
char		*f_readfile(t_game *game, int fd);
int			f_strcmp(char *str1, char *str2);
char		*f_strjoin(t_game *game, char const *s1, char const *s2);
size_t		f_strlen(const char *s);
int			f_char_count(char *str, char c);
char		*f_strchr(const char *s, int c);
void		*f_memcpy(void *dest, const void *src, size_t n);
char		**f_splitlines(t_game *game, char *text);
char		**f_split(t_game *game, char const *s, char c);
char		*f_strscmp(char *str1, int n, ...);
char		*f_strdup(t_game *game, const char *s);
bool		f_is_dig(char c);
bool		f_is_map_line(char *str);
void		f_set_color_config(t_game *game, t_line_type type, char *line);
bool		f_is_config_complete(t_game *game);
void		f_check_args(t_game *game, int argc, char **argv);
void		f_set_config_data(t_game *game);
t_line_type	f_set_input_line_type(t_game *game, char *line);
void		f_parse_input_file(t_game *game, char **argv);
void		f_set_map(t_game *game);
void		f_check_for_invalid_map_lines(t_game *game);
void		f_set_map_dimensions(t_game *game);
void		f_create_map_array(t_game *game);
void		f_fill_map_array(t_game *game);
void		f_check_open_walls(t_game *game);
void		f_check_single_starting_pos(t_game *game);
void		f_import_cub_file(t_game *game, char **argv);
void		f_set_texture_path(t_game *game, t_line_type type, char *line);
void		f_extract_game_pos(t_game *game);
void		f_setup_bonus(t_game *game);
void		f_setup_bonus_map(t_game *game);
void		f_print_error(const char *func, char *message);
void		*f_gc_malloc(t_game *game, size_t size);
void		f_gc_clean(t_game *game);
void		f_graceful_exit(t_game *game, int exit_code, const char *func,
				char *message);
void		f_init_main(t_game *game);
void		f_set_hooks(t_game *game);
void		f_print_map(t_game *game);
void		f_debug_info(t_game *game);
void		f_init_mlx(t_game *game);
void		f_init_mlx(t_game *game);
void		f_draw_square(t_game *game, t_square sq);
int			f_key_press(int keycode, t_game *game);
int			f_key_release(int keycode, t_game *game);
void		f_move_player(t_game *game);
void		f_clear_image(t_game *game);
void		f_draw_minimap(t_game *game);
bool		f_touch(float px, float py, t_game *game);
void		f_draw_walls(t_game *game);
void		f_draw_line(t_game *game, t_line line);
int			f_game_loop(t_game *game);
void		f_put_pixel(int x, int y, int color, t_game *game);
int			f_handle_close_button(void *param);
void		f_draw_full_square(t_game *game, t_square sq);
void		f_draw_circle_full(t_game *game, t_circle circle);
float		f_distance(t_coords p1, t_coords p2);
void		f_attempt_move(t_game *game, char dimension, float distance);
float		f_find_target(float current, float vector);
t_coords	f_next_grid_hit(t_coords current, float angle);
bool		f_is_round(float nbr);
bool		f_is_wall(t_game *game, t_coords pos);
void		f_load_dir_textures(t_game *game);
t_coords	f_next_wall_hit(t_game *game, t_coords current, float angle);
float		f_cosine_distance(t_coords a, t_coords b, float angle1,
				float angle2);
int			f_get_tex_color(t_game *game, t_coords wall_hit,
				float wall_height_ratio);
int			f_handle_mouse(int x, int y, void *param);
int			f_get_pixel(t_game *game, t_tex *tex, t_coords pos);
char		f_determine_tile_type(t_game *game, t_coords wall_hit, t_dir dir);
t_dir		f_determine_direction(t_game *game, t_coords wall_hit);
t_int_xy	f_determine_adjacent_tile(t_game *game);
void		f_remove_obstacle(t_game *game);
t_int_xy	f_determine_tile_coords(t_game *game, t_coords grid_hit, t_dir dir);
void		f_add_obstacle_to_respawn_list(t_game *game, t_int_xy coords,
				char type);
void		f_remove_from_respawn_list(t_game *game, t_obs_resp *obs);
void		f_handle_respawns(t_game *game);
void		f_draw_image(t_game *game, t_tex *tex, t_int_xy top_left);
void		f_draw_charmander(t_game *game);
void		f_draw_from_tex_to_area(t_game *game, t_tex *tex, t_rect area);
void		f_add_image_to_list(t_game *game, void *ptr);
void		f_destroy_images(t_game *game);
int			f_time_diff_ms(struct timeval *later, struct timeval *earlier);
void		f_load_texture(t_game *game, t_tex *tex);
void		f_load_bonus_textures(t_game *game);
void		f_load_anim(t_game *game, t_anim *anim, t_anim params, char *path);
void		f_remove_anim(t_game *game, t_anim_queue *anim);
void		f_superpose_anim(t_game *game, t_int_xy tile, t_coords relative,
				int *color);
void		f_add_to_anim_queue(t_game *game, t_int_xy coords, t_anim *anim);
void		f_draw_line_mapsafe(t_game *game, t_line line);
bool		f_is_visible(t_game *game, t_coords coords);
float		f_angle_diff(float alpha, float beta);
t_int_xy	f_find_char_in_map(t_game *game, char c);
void		f_check_game_end(t_game *game);
#endif // FUNCTIONS_H
