/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_charmander.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:51:47 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_draw_charmander(t_game *game)
{
	t_rect	area;

	area.width = WIDTH * 0.33;
	area.top_left.x = area.width;
	area.height = HEIGHT * 0.33;
	area.top_left.y = HEIGHT - area.height;
	f_draw_from_tex_to_area(game, &game->bonus_charmander, area);
}
