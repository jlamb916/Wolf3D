/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 14:08:16 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/07 14:35:43 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*result;
	size_t	numb[3];

	numb[0] = 0;
	numb[1] = 0;
	if (needle[numb[0]] == '\0')
		return ((char *)haystack);
	while (haystack[numb[1]] != '\0' && numb[1] < len)
	{
		numb[2] = numb[1];
		while (needle[numb[0]] == haystack[numb[2]] && numb[0] + numb[1] < len)
		{
			if (needle[numb[0] + 1] == '\0')
			{
				result = (char *)&haystack[numb[1]];
				return (result);
			}
			numb[0]++;
			numb[2]++;
		}
		numb[0] = 0;
		numb[1]++;
	}
	return (NULL);
}
