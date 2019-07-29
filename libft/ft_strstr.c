/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/21 18:06:35 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/06 13:28:02 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*result;
	int		numb[3];

	numb[0] = 0;
	numb[1] = 0;
	if (needle[numb[0]] == '\0')
		return ((char *)haystack);
	while (haystack[numb[1]] != '\0')
	{
		numb[2] = numb[1];
		while (needle[numb[0]] == haystack[numb[2]])
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
