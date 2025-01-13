/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_print_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:13:52 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/13 11:19:00 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	f_print_map(t_main *main)
{
	int	i;

	i = 0;
	printf("Main->map:\n");
	while (main->map[i])
	{
		printf("%s\n", main->map[i]);
		i++;
	}
}
