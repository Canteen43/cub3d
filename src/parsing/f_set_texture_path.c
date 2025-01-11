/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_texture_path.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:52:45 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 13:21:24 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// TODO: write function description
// TODO: figure out return value and/or freeing mechanism
void	f_set_texture_path(t_main *main, t_line_type type, char *line)
{
	char	*target;
	char	**split_res;

	if (type == NORTH)
		target = main->no_txtr_path;
	if (type == EAST)
		target = main->ea_txtr_path;
	if (type == SOUTH)
		target = main->so_txtr_path;
	if (type == WEST)
		target = main->we_txtr_path;
	if (target != NULL)
		f_print_error(__func__, "Redefintion of texture path.");
	split_res = f_split(line, ' ');
	if (!split_res || !split_res[0])
		f_print_error(__func__, "Split() failed.");
	if (!split_res[1])
		f_print_error(__func__, "Too few args in texture line.");
	if (split_res[2])
		f_print_error(__func__, "Too many args in texture line.");
	target = f_strdup(res[1]);
	if (target == NULL)
		f_print_error(__func__, "Strdup() failed.");
	f_free_split(split_res);
}
