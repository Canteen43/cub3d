/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 14:31:19 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 10:25:59 by kweihman         ###   ########.fr       */
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
}								t_dir;

// Coordinate struct
typedef struct s_coordinates
{
	float						x;
	float						y;
}								t_coords;

// Int coordinate struct
typedef struct s_integer_coordinates
{
	int							x;
	int							y;
}								t_int_xy;

// Line struct
typedef struct s_line
{
	int							color;
	t_coords					start;
	t_coords					end;
}								t_line;

// Circle struct
typedef struct s_circle
{
	int							color;
	float						radius;
	t_coords					center;
}								t_circle;

// Square struct
typedef struct s_square
{
	int							color;
	float						size;
	t_coords					top_left;
}								t_square;

// Rectangle struct
typedef struct s_rectangle
{
	int							color;
	t_int_xy					top_left;
	int							width;
	int							height;
}								t_rect;

// Texture struct
typedef struct s_texture
{
	char						*path;
	void						*img_ptr;
	int							width;
	int							height;
	void						*data;
	int							bpp;
	int							size_line;
	int							endian;
}								t_tex;

// Respawn queue
typedef struct s_obstacle_respawn
{
	char						type;
	t_int_xy					coords;
	struct s_obstacle_respawn	*prev;
	struct s_obstacle_respawn	*next;
}								t_obstacle_respawn;

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
}								t_line_type;

// Image destruction struct
typedef struct s_image_to_destroy
{
	void						*img_prt;
	struct s_image_to_destroy	*next;
}								t_image;

// Garbage collection struct
typedef struct s_gnode
{
	void						*ptr;
	struct s_gnode				*next;
}								t_gnode;

// Main struct
// Overarching struct that holds all variables that might need to be accessed.
typedef struct s_game
{
	t_gnode						*gc_head;
	t_tex						north;
	t_tex						east;
	t_tex						south;
	t_tex						west;
	t_tex						bonus_cuttable;
	t_tex						bonus_wall;
	t_tex						bonus_charmander;
	int							floor_color;
	int							ceiling_color;
	char						*entire_cubfile;
	char						**cubfile_line_by_line;
	int							cubfile_fd;
	int							map_line_count;
	int							map_line_width;
	char						**map;
	void						*mlx;
	void						*win;
	void						*img;

	char						*data;
	int							bpp;
	int							size_line;
	int							endian;
	int							pix_per_unit;
	float						focal_length;

	bool						key_up;
	bool						key_right;
	bool						key_left;
	bool						key_down;
	bool						left_rotate;
	bool						right_rotate;
	bool						bonus;

	float						player_angle;
	t_coords					player_pos;
	t_obstacle_respawn			*or_head;
}								t_game;

#endif // STRUCTS_H
