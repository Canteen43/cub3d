/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:11:03 by kweihman          #+#    #+#             */
/*   Updated: 2025/01/05 12:14:04 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*Returns how many times char c occurs in str c. Return -1 if str is NULL.*/
int	f_char_count(char *str, char c)
{
	int	count;

	if (!str)
		return (-1);
	while (*str)
	{
		if (*str == c)
			count++;
		str++;
	}
	return (count);
}
