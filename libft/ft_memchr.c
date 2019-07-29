/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:25:32 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/19 13:03:12 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*a;

	i = 0;
	a = (unsigned char*)s;
	while (n > 0)
	{
		if (a[i] == (unsigned char)c)
		{
			return ((void *)&s[i]);
		}
		n--;
		i++;
	}
	return (NULL);
}
