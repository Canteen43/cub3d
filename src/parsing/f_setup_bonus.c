/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_setup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:14:34 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/29 18:58:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_setup_bonus(t_game *game)
{
	game->ceiling_color = SKY_BLUE;
	game->floor_color = POKEGRASS;
	game->bonus_cuttable.path = "textures/cuttable.xpm";
	game->bonus_wall.path = "textures/tree.xpm";
	f_setup_bonus_map(game);
}
