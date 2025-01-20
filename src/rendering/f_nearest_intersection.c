/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_nearest_intersection.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:37:59 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/20 19:57:01 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_coords	f_nearest_intersection(t_coords current, float angle)
{
	t_coords	vector;
	float		target_x;
	float		target_y;
	t_coords	intersection;
	float		factor_needed;

	vector = (t_coords){cos(angle), sin(angle)};
	target_x = f_find_target(current.x, vector.x);
	target_y = f_find_target(current.y, vector.y);
	factor_needed = (target_x - current.x) / vector.x;
	if (((target_y - current.y) / vector.y) < factor_needed)
		factor_needed = (target_y - current.y) / vector.y;
	intersection.x = current.x + vector.x * factor_needed;
	intersection.y = current.y + vector.y * factor_needed;
	return (intersection);
}
