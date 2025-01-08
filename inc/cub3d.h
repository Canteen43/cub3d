/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 17:54:37 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/08 19:10:26 by kweihman         ###   ########.fr       */
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
// For malloc(), free()
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
}			t_line_type;

// Main struct
typedef struct s_main
{
	char	*no_txtr_path;
	char	*ea_txtr_path;
	char	*so_txtr_path;
	char	*we_txtr_path;
	int		floor_color;
	int		ceiling_color;
}			t_main;

// Function declarations
// Utils
void		f_bzero(void *s, size_t n);
char		*f_readfile(int fd);
int			f_strcmp(char *str1, char *str2);
char		*f_strjoin(char const *s1, char const *s2);
size_t		f_strlen(const char *s);
int			f_char_count(char *str, char c);
char		*f_strchr(const char *s, int c);
void		*f_memcpy(void *dest, const void *src, size_t n);
char		**f_splitlines(char *text);
char		**f_split(char const *s, char c);
void		f_free_split(char **array);
char		*f_strscmp(char *str1, int n, ...);

void		f_error_and_exit(char *error, int exit_code);
void		f_check_args(int argc, char **argv);
bool		f_is_map_line(char *str);
#endif // CUB3D_H