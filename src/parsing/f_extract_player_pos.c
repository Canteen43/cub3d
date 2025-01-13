/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_extract_player_pos.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 14:13:56 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/13 14:19:41 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_extract_player_pos(t_main *main)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (main->map[i])
	{
		while (main->map[i][j])
		{
			if (f_strchr("NESW", main->map[i][j]))
			{
				main->map[i][j] = '0';
				main->player_x = i + 0.5f;
				main->player_y = i + 0.5f;
				return ;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
