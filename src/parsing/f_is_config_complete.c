/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_config_complete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:06:12 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*Returns whether all config data has been set or not.*/
bool	f_is_config_complete(t_game *game)
{
	if (game->north.path && game->east.path && game->south.path
		&& game->west.path && game->ceiling_color != -1
		&& game->floor_color != -1)
		return (true);
	return (false);
}
