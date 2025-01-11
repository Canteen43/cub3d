/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle_cub_input.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:27:30 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/11 17:47:49 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_handle_cub_input(t_main *main, char **argv)
{
	main->cubfile_fd = open(argv[1], O_RDONLY, NULL);
	if (main->cubfile_fd == -1)
		f_graceful_exit(main, 1, __func__, "Open() failed."); 
	main->entire_cubfile = f_readfile(main->cubfile_fd);
	if (!main->entire_cubfile)
		f_graceful_exit(main, 1, __func__, "Reading .cub-file failed."); 
	main->cubfile_line_by_line = f_splitlines(main->entire_cubfile);
	if (!main->cubfile_line_by_line)
		f_graceful_exit(main, 1, __func__, "Splitlines() failed."); 
	f_set_config_data(main);
}
