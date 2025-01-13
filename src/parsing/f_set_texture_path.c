/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:52:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 18:11:50 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* Checks if given line fits texture-path-line-format and sets texture path
if so. Exits on error. */
void	f_set_texture_path(t_main *main, t_line_type type, char *line)
{
	char	**target;
	char	**words;

	if (type == NORTH)
		target = &main->no_txtr_path;
	if (type == EAST)
		target = &main->ea_txtr_path;
	if (type == SOUTH)
		target = &main->so_txtr_path;
	if (type == WEST)
		target = &main->we_txtr_path;
	if (*target != NULL)
		f_graceful_exit(main, 1, __func__, "Redefintion of texture path.");
	words = f_split(main, line, ' ');
	if (!words[1])
		f_graceful_exit(main, 1, __func__, "Too few args in texture line.");
	if (words[2])
		f_graceful_exit(main, 1, __func__, "Too many args in texture line.");
	*target = words[1];
}
