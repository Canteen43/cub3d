/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:50:18 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/23 18:42:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

#define EPSILON 0.00001

bool	f_is_round(float nbr)
{
	return (fabs(nbr - roundf(nbr)) < EPSILON);
}
