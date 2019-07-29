/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 02:49:31 by jolam             #+#    #+#             */
/*   Updated: 2019/05/23 02:55:40 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	fixmap(t_mlx *m)
{
	int i;
	int j;

	i = 0;
	while (i < m->mapw)
	{
		j = 0;
		while (j < m->maph)
		{
			if (m->map[j][i] == 11)
				m->map[j][i] = 0;
			j++;
		}
		i++;
	}
}

int		floodfill(t_mlx *m, int x, int y)
{
	static int target = 0;
	static int replace = 11;

	if (m->map[y][x] != target)
		return (1);
	if ((x == 0 && m->map[y][x] == 0) || (x == m->mapw - 1 && m->map[y][x] == 0)
	|| (y == 0 && m->map[y][x] == 0) || (y == m->maph - 1 && m->map[y][x] == 0))
		ft_putstrexit("Error: Invalid Map");
	m->map[y][x] = replace;
	floodfill(m, x + 1, y);
	floodfill(m, x - 1, y);
	floodfill(m, x, y + 1);
	floodfill(m, x, y - 1);
	return (1);
}
