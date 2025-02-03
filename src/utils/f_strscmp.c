/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strscmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:13:28 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

/*Uses f_strcmp to compare n strings and returns the first string that
is equal.*/
char	*f_strscmp(char *str1, int n, ...)
{
	va_list	strs;
	char	*str;

	va_start(strs, n);
	while (n)
	{
		str = va_arg(strs, char *);
		if (f_strcmp(str, str1) == 0)
		{
			va_end(strs);
			return (str);
		}
		n--;
	}
	va_end(strs);
	return (NULL);
}
