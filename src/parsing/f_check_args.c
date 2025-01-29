/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_check_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:49:08 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/29 18:24:42 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_check_args(t_game *game, int argc, char **argv)
{
	size_t	len;

	if (argc != 2)
		f_graceful_exit(game, 1, __func__, "Wrong nbr of args.");
	len = f_strlen(argv[1]);
	if (f_strcmp(".cub", argv[1] + len - 4))
		f_graceful_exit(game, 1, __func__, "Arg has to end with '.cub'.");
	if (f_strcmp(argv[1], "maps/bonus.cub") == 0)
		game->bonus = true;
}
