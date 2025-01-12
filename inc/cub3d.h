/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 11:16:57 by kweihman         ###   ########.fr       */
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

// Macros
# define ERR_ARGNBR "Wrong number of args. Argc needs to be 2"
# define ERR_ARGNAME "Wrong name of arg. Arg needs to have .cub extension"
# define BUFFER_SIZE 256

// Token Type enum
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
typedef struct s_main
{
	t_gnode			*gc_head;
	char			*no_txtr_path;
	char			*ea_txtr_path;
	char			*so_txtr_path;
	char			*we_txtr_path;
	int				floor_color;
	int				ceiling_color;
	char			*entire_cubfile;
	char			**cubfile_line_by_line;
	int				cubfile_fd;
	int				map_line_count;
	int				map_line_width;
}					t_main;

// Function declarations
// Utils
void				f_bzero(void *s, size_t n);
char				*f_readfile(int fd);
int					f_strcmp(char *str1, char *str2);
char				*f_strjoin(char const *s1, char const *s2);
size_t				f_strlen(const char *s);
int					f_char_count(char *str, char c);
char				*f_strchr(const char *s, int c);
void				*f_memcpy(void *dest, const void *src, size_t n);
char				**f_splitlines(char *text);
char				**f_split(char const *s, char c);
void				f_free_split(char **array);
char				*f_strscmp(char *str1, int n, ...);
char				*f_strdup(const char *s);

// Parsing
bool				f_is_map_line(char *str);
void				f_set_color_config(t_main *main, t_line_type type,
						char *line);
bool				f_is_config_complete(t_main *main);
void				f_check_args(int argc, char **argv);
void				f_set_config_data(t_main *main, char **cublines);
t_line_typ			f_set_input_line_type(char *line);
void				f_handle_cub_input(t_main *main, char **argv);
void				f_set_map(t_main *main);
void				f_check_for_invalid_map_lines(t_main *main);

// Core
void				f_print_error(char *func, char *message);
void				*f_gc_f_gc_malloc(main, t_main *main, size_t size);
void				f_gc_clean(t_main *main);
void				f_graceful_exit(t_main *main, int exit_code, char *func,
						char *message);
#endif // CUB3D_H