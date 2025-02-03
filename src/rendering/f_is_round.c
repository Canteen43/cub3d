/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_is_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 19:50:18 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

bool	f_is_round(float nbr)
{
	if (truncf(nbr) == nbr)
		return (true);
	else
		return (false);
}
