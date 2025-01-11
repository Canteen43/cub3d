/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_map_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 19:04:04 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/08 19:10:05 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Returns whether the given str qualifies as a valid line in the map.*/
bool	f_is_map_line(char *str)
{
	bool	start_pos_found;

	start_pos_found = false;
	if (!str)
		return (false);
	while (*str)
	{
		if (!f_strchr(" 10NSWE", *str))
			return (false);
		if (f_strchr("NSWE", *str))
		{
			if (start_pos_found)
				return (false);
			else
				start_pos_found = true;
		}
		str++;
	}
	return (true);
}
