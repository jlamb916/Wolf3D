/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strafe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 17:23:35 by knguyen-          #+#    #+#             */
/*   Updated: 2019/05/24 17:34:26 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	rightstrafe(t_mlx *m)
{
	m->map[(int)(m->posx)][(int)(m->posy - m->dirx * m->movespeed)] == 0 ?
		m->posy -= m->dirx * m->movespeed : 0;
	m->map[(int)(m->posx + m->diry * m->movespeed)][(int)(m->posy)] == 0 ?
		m->posx += m->diry * m->movespeed : 0;
	redraw(m);
	return (0);
}

int	leftstrafe(t_mlx *m)
{
	m->map[(int)(m->posx)][(int)(m->posy + m->dirx * m->movespeed)] == 0 ?
		m->posy += m->dirx * m->movespeed : 0;
	m->map[(int)(m->posx - m->diry * m->movespeed)][(int)(m->posy)] == 0 ?
		m->posx -= m->diry * m->movespeed : 0;
	redraw(m);
	return (0);
}
