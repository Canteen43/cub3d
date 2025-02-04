/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:31:19 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 12:55:09 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// Direction enum
// Not the direction the side is facing but the direction relative to player
typedef enum e_direction
{
	north,
	east,
	south,
	west,
}						t_dir;

// Coordinate struct
typedef struct s_coordinates
{
	float				x;
	float				y;
}						t_coords;

// Int coordinate struct
typedef struct s_integer_coordinates
{
	int					x;
	int					y;
}						t_int_xy;

// Line struct
typedef struct s_line
{
	int					color;
	t_coords			start;
	t_coords			end;
}						t_line;

// Circle struct
typedef struct s_circle
{
	int					color;
	float				radius;
	t_coords			center;
}						t_circle;

// Square struct
typedef struct s_square
{
	int					color;
	float				size;
	t_coords			top_left;
}						t_square;

// Rectangle struct
typedef struct s_rectangle
{
	int					color;
	t_int_xy			top_left;
	int					width;
	int					height;
}						t_rect;

// Texture struct
typedef struct s_texture
{
	char				*path;
	void				*img_ptr;
	int					width;
	int					height;
	void				*data;
	int					bpp;
	int					size_line;
	int					endian;
}						t_tex;

// Struct: Node in list of obstacles waiting for respawn
typedef struct s_obs_resp
{
	char				type;
	t_int_xy			coords;
	struct s_obs_resp	*prev;
	struct s_obs_resp	*next;
}						t_obs_resp;

// Enum used for classifying lines during parse
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

// Struct: Node in list of images to be destroyed at exit
typedef struct s_img
{
	void				*ptr;
	struct s_img		*next;
}						t_img;

// Struct: Animation
typedef struct s_anim
{
	t_tex				*frames;
	int					nbr_frames;
	int					duration_ms;
}						t_anim;

// Struct: Node in list of ongoing animations
typedef struct t_anim_queue
{
	t_anim				anim;
	t_int_xy			coords;
	struct timeval		start;
	struct s_aq			*next;
}						t_anim_queue;

// Garbage collection struct
typedef struct s_gnode
{
	void				*ptr;
	struct s_gnode		*next;
}						t_gnode;

// Main struct
// Overarching struct that holds all variables that might need to be accessed.
typedef struct s_game
{
	t_tex				north;
	t_tex				east;
	t_tex				south;
	t_tex				west;
	t_tex				bonus_cuttable;
	t_tex				bonus_wall;
	t_tex				bonus_charmander;

	t_anim				cut;

	t_gnode				*gc_head;
	int					floor_color;
	int					ceiling_color;
	char				*entire_cubfile;
	char				**cubfile_line_by_line;
	int					cubfile_fd;
	int					map_line_count;
	int					map_line_width;
	char				**map;
	void				*mlx;
	void				*win;
	void				*img;

	char				*data;
	int					bpp;
	int					size_line;
	int					endian;
	int					pix_per_unit;
	float				focal_length;

	bool				key_up;
	bool				key_right;
	bool				key_left;
	bool				key_down;
	bool				left_rotate;
	bool				right_rotate;
	bool				bonus;

	float				player_angle;
	t_coords			player_pos;
	t_obs_resp			*or_head;
	t_img				*img_head;
}						t_game;

#endif // STRUCTS_H
