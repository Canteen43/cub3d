/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_distance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:36:07 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

float	f_distance(t_coords p1, t_coords p2)
{
	return (sqrtf(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2)));
}
