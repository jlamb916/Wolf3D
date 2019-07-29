/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 12:15:54 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/19 14:42:57 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	neg_adder(int n, char *result)
{
	if (n)
		result[0] = '-';
}

char		*ft_itoa(int n)
{
	char	*result;
	int		numb[3];

	numb[0] = 0;
	numb[1] = 1;
	if (n < 0 && numb[1]++)
	{
		if (n == -2147483648)
			return (ft_strdup("-2147483648"));
		numb[0] = 1;
		n *= -1;
	}
	numb[2] = n;
	while ((numb[2] /= 10) > 0)
		numb[1]++;
	result = ft_strnew(numb[1]);
	if (!result)
		return (NULL);
	while (numb[1]-- >= 1)
	{
		result[numb[1]] = (n % 10) + '0';
		n /= 10;
	}
	neg_adder(numb[0], result);
	return (result);
}
