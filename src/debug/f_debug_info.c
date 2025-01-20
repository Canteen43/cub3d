/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_debug_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 20:04:06 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/20 20:25:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_debug_info(t_player *player)
{
	printf("Nearest wall: X=%f, Y=%f\n", player->intersection.x,
		player->intersection.y);
}
