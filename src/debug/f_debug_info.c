/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_debug_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: glevin <glevin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:04:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/25 15:47:10 by glevin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_debug_info(t_game *game)
{
	// (void)game;
	printf("Put your needs here.\n");
	printf("x: %f, y: %f", game->player_pos.x, game->player_pos.y);	
	printf("--------------------------------\n");
	game->debug_flag = true;
}
