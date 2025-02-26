/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_angle_diff.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/23 17:49:57 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/23 18:42:25 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

float	f_angle_diff(float alpha, float beta)
{
	float	diff;

	diff = alpha - beta;
	while (diff < -PI)
		diff += 2 * PI;
	while (diff > PI)
		diff -= 2 * PI;
	if (diff < 0)
		diff = -diff;
	return (diff);
}
