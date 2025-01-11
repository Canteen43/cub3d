/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_config_complete.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:06:12 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 16:10:05 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Returns whether all config data has been set or not.*/
bool	f_is_config_complete(t_main *main)
{
	if (main->no_txtr_path && main->ea_txtr_path && main->so_txtr_path
		&& main->we_txtr_path && main->ceiling_color != -1
		&& main->floor_color != -1)
		return (true);
	return (false);
}
