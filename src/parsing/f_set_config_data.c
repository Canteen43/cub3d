/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_config_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:35:13 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 17:53:48 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_set_config_data(t_main *main)
{
	int			i;
	t_line_typ	type;
	char		**lines;

	lines = main->cubfile_line_by_line;
	i = 0;
	while (lines[i])
	{
		type = f_set_input_line_type(lines[i]);
		if (type == FLOOR || type == CEILING)
			f_set_color_config(main, type, lines[i]);
		else if (type == NORTH || type == EAST || type == SOUTH || type == WEST)
			f_set_texture_path(main, type, lines[i]);
		else if (type == WRONG)
			f_graceful_exit(main, 1, __func__, "Invalid line encountered.");
		else if (type == MAP && !f_is_config_complete(main))
			f_graceful_exit(main, 1, __func__, "Map line before config over."); 
		else if (type == MAP && f_is_config_complete(main))
			break ;
	}
}
