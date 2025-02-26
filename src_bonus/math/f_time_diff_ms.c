/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_time_diff_ms.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:52:28 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/04 17:41:01 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

int	f_time_diff_ms(struct timeval *later, struct timeval *earlier)
{
	int	result;

	result = (later->tv_sec - earlier->tv_sec) * 1000 + (later->tv_usec
			- earlier->tv_usec) / 1000;
	return (result);
}
