/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_read_cubfile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 16:27:30 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/05 13:39:17 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_read_cubfile(t_main *main, char **argv)
{
	int		fd;
	char	**cublines;

	fd = open(argv[1], O_RDONLY, NULL);
	cublines = f_splitlines(f_readfile(fd));
	f_set_config_data(main, cublines);

	
