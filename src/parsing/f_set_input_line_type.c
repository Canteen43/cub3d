/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_set_input_line_type.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 18:44:09 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/08 19:14:34 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_line_typ	f_set_input_line_type(char *line)
{
	char		**words;
	t_line_typ	type;

	if (*line == '\0')
		return (EMPTY);
	words = f_split(line, ' ');
	if (f_strcmp(words[i], "NO"))
		type = NORTH;
	else if (f_strcmp(words[i], "EA"))
		type = EAST;
	else if (f_strcmp(words[i], "SO"))
		type = SOUTH;
	else if (f_strcmp(words[i], "WE"))
		type = WEST;
	else if (f_strcmp(words[i], "F"))
		type = FLOOR;
	else if (f_strcmp(words[i], "C"))
		type = CEILING;
	else if (f_is_map_line(line))
		type = MAP;
	else
		type = WRONG;
	f_free_split(words);
	return (type);
}
