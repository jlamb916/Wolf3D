/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 12:18:32 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/19 12:55:28 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*out;

	i = 0;
	if (!s || !f)
		return (NULL);
	out = (char *)malloc(sizeof(*out) * (ft_strlen(s) + 1));
	if (!out)
		return (NULL);
	while (s[i])
	{
		out[i] = (*f)(s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
