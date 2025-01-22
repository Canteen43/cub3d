/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:27:30 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/22 09:30:12 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_handle_cub_file(t_game *game, char **argv)
{
	f_import_cub_file(game, argv);
	f_set_config_data(game);
	f_set_map(game);
}
