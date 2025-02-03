/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 13:53:58 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*Expects two non-NULL strings and returns str1 minus str2 at the first char
that differs.*/
int	f_strcmp(char *str1, char *str2)
{
	while (*str1)
	{
		if (*str1 != *str2)
			return (*str1 - *str2);
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
