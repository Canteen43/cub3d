/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_memcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kweihman <kweihman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 12:33:51 by kweihman          #+#    #+#             */
/*   Updated: 2025/02/03 14:41:51 by kweihman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	*f_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	dest2 = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n)
	{
		dest2[i] = src2[i];
		i++;
	}
	return (dest);
}
