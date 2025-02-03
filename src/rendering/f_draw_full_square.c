/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_draw_full_square.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 12:14:25 by glevin            #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	f_draw_full_square(t_game *game, t_square sq)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < sq.size)
	{
		j = 0;
		while (j < sq.size)
		{
			f_put_pixel(sq.top_left.x + i, sq.top_left.y + j, sq.color, game);
			j++;
		}
		i++;
	}
}
