/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parse_input_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:27:30 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 10:30:10 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_parse_input_file(t_game *game, char **argv)
{
	f_import_cub_file(game, argv);
	if (!game->bonus)
	{
		f_set_config_data(game);
		f_set_map(game);
		return ;
	}
	f_setup_bonus(game);
}
