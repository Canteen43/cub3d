/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_touch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:19:13 by glevin            #+#    #+#             */
/*   Updated: 2025/01/18 12:19:18 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	f_touch(float px, float py, t_game *game)
{
	int	x;
	int	y;

	x = px / BLOCK;
	y = py / BLOCK;
	if (game->main->map[x][y] == '1')
	{
		return (true);
	}
	return (false);
}
