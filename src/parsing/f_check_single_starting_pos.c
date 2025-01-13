/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_single_starting_pos.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:05:33 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/13 17:16:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_check_single_starting_pos(t_main *main)
{
	int		i;
	int		j;
	bool	startpos_found;

	i = 0;
	j = 0;
	startpos_found = false;
	while (main->map[i])
	{
		while (main->map[i][j])
		{
			if (f_strchr("NESW", main->map[i][j]))
			{
				if (!startpos_found)
					startpos_found = true;
				else if (startpos_found)
					f_graceful_exit(main, 1, __func__, "Multiple start pos.");
			}
			j++;
		}
		j = 0;
		i++;
	}
	if (!startpos_found)
		f_graceful_exit(main, 1, __func__, "No start pos found.");
}
