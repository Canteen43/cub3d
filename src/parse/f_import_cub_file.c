/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_import_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:48:52 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

void	f_import_cub_file(t_game *game, char **argv)
{
	game->cubfile_fd = open(argv[1], O_RDONLY, NULL);
	if (game->cubfile_fd == -1)
		f_graceful_exit(game, 1, __func__, "Open() failed.");
	game->entire_cubfile = f_readfile(game, game->cubfile_fd);
	if (!game->entire_cubfile)
		f_graceful_exit(game, 1, __func__, "Reading .cub-file failed.");
	if (*game->entire_cubfile == '\0')
		f_graceful_exit(game, 1, __func__, "Empty .cub-file.");
	game->cubfile_line_by_line = f_splitlines(game, game->entire_cubfile);
}
