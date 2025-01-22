/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:52:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 18:11:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if given line fits texture-path-line-format and sets texture path
if so. Exits on error. */
void	f_set_texture_path(t_game *game, t_line_type type, char *line)
{
	char	**target;
	char	**words;

	if (type == NORTH)
		target = &game->north.path;
	if (type == EAST)
		target = &game->east.path;
	if (type == SOUTH)
		target = &game->south.path;
	if (type == WEST)
		target = &game->west.path;
	if (*target != NULL)
		f_graceful_exit(game, 1, __func__, "Redefintion of texture path.");
	words = f_split(game, line, ' ');
	if (!words[1])
		f_graceful_exit(game, 1, __func__, "Too few args in texture line.");
	if (words[2])
		f_graceful_exit(game, 1, __func__, "Too many args in texture line.");
	if (strcmp(".xpm", words[1] + f_strlen(words[1]) - 4))
		f_graceful_exit(game, 1, __func__, "Texture not ending with .xpm.");
	*target = words[1];
}
