/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 19:28:16 by knguyen-          #+#    #+#             */
/*   Updated: 2018/12/19 14:08:54 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	int nb_copy;
	int nb_size;

	nb_size = 1;
	if (n < 0)
	{
		ft_putchar('-');
		if (n == -2147483648)
		{
			ft_putchar('2');
			n += 2000000000;
		}
		n *= -1;
	}
	nb_copy = n;
	while ((nb_copy /= 10) > 0)
		nb_size *= 10;
	while (nb_size > 0)
	{
		ft_putchar(n / nb_size + '0');
		n %= nb_size;
		nb_size /= 10;
	}
}
