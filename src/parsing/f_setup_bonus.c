/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_setup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:14:34 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/28 16:22:50 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_setup_bonus(t_game *game)
{
	game->north.path = "textures/tree.xpm";
	game->east.path = "textures/tree.xpm";
	game->south.path = "textures/tree.xpm";
	game->west.path = "textures/tree.xpm";
	game->ceiling_color = CORAL;
	game->floor_color = LIME;
	game->cuttable.path = "textures/cuttable.xpm"
}
