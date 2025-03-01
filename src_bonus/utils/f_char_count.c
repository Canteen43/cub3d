/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_char_count.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:11:03 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 16:48:16 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers.h"

/*Returns how many times char c occurs in str c. Return -1 if str is NULL.*/
int	f_char_count(char *str, char c)
{
	int	count;

	count = 0;
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
