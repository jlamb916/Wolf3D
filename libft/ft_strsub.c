/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:43:28 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/19 12:39:47 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	out = ft_strnew(len);
	if (!out)
		return (NULL);
	while (i < len)
	{
		out[i] = s[start];
		start++;
		i++;
	}
	return (out);
}
