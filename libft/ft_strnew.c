/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 13:18:11 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/19 12:09:55 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	result = (char*)malloc(sizeof(*result) * size + 1);
	if (!result)
		return (NULL);
	else
	{
		while (i <= size)
		{
			result[i] = '\0';
			i++;
		}
		return (result);
	}
}
