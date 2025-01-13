/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_import_cub_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 13:48:52 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/12 18:13:05 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_import_cub_file(t_main *main, char **argv)
{
	main->cubfile_fd = open(argv[1], O_RDONLY, NULL);
	if (main->cubfile_fd == -1)
		f_graceful_exit(main, 1, __func__, "Open() failed.");
	main->entire_cubfile = f_readfile(main, main->cubfile_fd);
	if (!main->entire_cubfile)
		f_graceful_exit(main, 1, __func__, "Reading .cub-file failed.");
	main->cubfile_line_by_line = f_splitlines(main, main->entire_cubfile);
}
