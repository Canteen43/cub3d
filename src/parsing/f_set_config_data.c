/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_config_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 13:35:13 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 16:15:45 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_set_config_data(t_main *main, char **cublines)
{
	int			i;
	t_line_typ	type;
	bool		f_is;

	i = 0;
	f_is = false;
	while (cublines[i])
	{
		type = f_set_input_line_type(cublines[i]);
		if (type == WRONG)
			f_print_error(__func__, "Invalid line encountered.");
		else if (type == FLOOR || type == CEILING)
			f_set_color_config(main, type, cublines[i]);
		else if (type == NORTH || type == EAST || type == SOUTH || type == WEST)
			f_set_texture_path(main, type, cublines[i]);
		else if (type == MAP && !f_is_config_complete(main))
			f_print_error(__func__, "Map line before config was set."); 
		else if (type == MAP && f_is_config_complete(main))
			break ;
	}
}
