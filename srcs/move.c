/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:31:44 by knguyen-          #+#    #+#             */
/*   Updated: 2019/05/23 17:55:58 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int	forward(t_mlx *m)
{
	m->map[(int)(m->posx + m->dirx * m->movespeed)][(int)m->posy] == 0 ?
		m->posx += m->dirx * m->movespeed : 0;
	m->map[(int)m->posx][(int)(m->posy + m->diry * m->movespeed)] == 0 ?
		m->posy += m->diry * m->movespeed : 0;
	redraw(m);
	return (0);
}

int	back(t_mlx *m)
{
	m->map[(int)(m->posx - m->dirx * m->movespeed)][(int)m->posy] == 0 ?
		m->posx -= m->dirx * m->movespeed : 0;
	m->map[(int)m->posx][(int)(m->posy - m->diry * m->movespeed)] == 0 ?
		m->posy -= m->diry * m->movespeed : 0;
	redraw(m);
	return (0);
}

int	right(t_mlx *m)
{
	m->planexsave = m->planex;
	m->dirxsave = m->dirx;
	m->dirx = m->dirx * cos(-m->rotspeed) - m->diry * sin(-m->rotspeed);
	m->diry = m->dirxsave * sin(-m->rotspeed) + m->diry * cos(-m->rotspeed);
	m->planex = m->planex * cos(-m->rotspeed) - m->planey * sin(-m->rotspeed);
	m->planey = m->planexsave * sin(-m->rotspeed)
		+ m->planey * cos(-m->rotspeed);
	redraw(m);
	return (0);
}

int	left(t_mlx *m)
{
	m->planexsave = m->planex;
	m->dirxsave = m->dirx;
	m->dirx = m->dirx * cos(m->rotspeed) - m->diry * sin(m->rotspeed);
	m->diry = m->dirxsave * sin(m->rotspeed) + m->diry * cos(m->rotspeed);
	m->planex = m->planex * cos(m->rotspeed) - m->planey * sin(m->rotspeed);
	m->planey = m->planexsave * sin(m->rotspeed)
		+ m->planey * cos(m->rotspeed);
	redraw(m);
	return (0);
}
