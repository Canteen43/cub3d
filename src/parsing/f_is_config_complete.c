/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_config_complete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:06:12 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/21 14:07:43 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Returns whether all config data has been set or not.*/
bool	f_is_config_complete(t_game *game)
{
	if (game->no_txtr_path && game->ea_txtr_path && game->so_txtr_path
		&& game->we_txtr_path && game->ceiling_color != -1
		&& game->floor_color != -1)
		return (true);
	return (false);
}
