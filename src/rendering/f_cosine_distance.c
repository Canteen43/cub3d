/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_cosine_distance.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 15:30:42 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/22 15:33:52 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	f_cosine_distance(t_coords a, t_coords b, float angle1, float angle2)
{
	return (f_distance(a, b) * cos(angle1 - angle2));
}
