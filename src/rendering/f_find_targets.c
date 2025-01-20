/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_find_targets.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:11:46 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/20 19:59:32 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	f_find_target(float current, float vector)
{
	float	target;

	if (f_is_round(current))
	{
		if (vector >= 0)
			target = current + 1;
		else
			target = current - 1;
	}
	else
	{
		if (vector >= 0)
			target = ceilf(current);
		else
			target = floorf(current);
	}
	return (target);
}
