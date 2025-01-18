/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_init.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 10:46:20 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/18 14:11:31 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_init(t_main *main)
{
	f_bzero(main, sizeof(t_main));
	main->ceiling_color = -1;
	main->floor_color = -1;
}
