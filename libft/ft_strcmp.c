/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 20:09:38 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/19 15:02:40 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*scpy1;
	unsigned char	*scpy2;
	size_t			i;

	i = 0;
	scpy1 = (unsigned char *)s1;
	scpy2 = (unsigned char *)s2;
	while (scpy1[i] != '\0')
	{
		if (scpy1[i] != scpy2[i])
			return (scpy1[i] - scpy2[i]);
		i++;
	}
	if (scpy2[i] != '\0')
		return (scpy1[i] - scpy2[i]);
	return (0);
}
