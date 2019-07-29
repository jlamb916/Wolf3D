/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 02:46:57 by jolam             #+#    #+#             */
/*   Updated: 2019/05/24 17:34:54 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_dist(t_mlx *m, t_frame *frame)
{
	if (frame->raydirx < 0)
	{
		frame->changex = -1;
		frame->sidedistx = (m->posx - frame->mapx) * frame->deltax;
	}
	else
	{
		frame->changex = 1;
		frame->sidedistx = (frame->mapx + 1.0 - m->posx) * frame->deltax;
	}
	if (frame->raydiry < 0)
	{
		frame->changey = -1;
		frame->sidedisty = (m->posy - frame->mapy) * frame->deltay;
	}
	else
	{
		frame->changey = 1;
		frame->sidedisty = (frame->mapy + 1.0 - m->posy) * frame->deltay;
	}
}

void	calc_wall_hit(t_mlx *m, t_frame *frame)
{
	while (frame->wall == 0)
	{
		if (frame->sidedistx < frame->sidedisty)
		{
			frame->sidedistx += frame->deltax;
			frame->mapx += frame->changex;
			frame->side = 0;
		}
		else
		{
			frame->sidedisty += frame->deltay;
			frame->mapy += frame->changey;
			frame->side = 1;
		}
		if (m->map[frame->mapx][frame->mapy] > 0 &&
			m->map[frame->mapx][frame->mapy] != 11)
			frame->wall = 1;
	}
}

void	calc_floor_dist(t_mlx *m, t_frame *frame)
{
	if (frame->side == 0 && frame->raydirx > 0)
	{
		frame->floorx = frame->mapx;
		frame->floory = frame->mapy + m->wallx;
	}
	else if (frame->side == 0 && frame->raydirx < 0)
	{
		frame->floorx = frame->mapx + 1;
		frame->floory = frame->mapy + m->wallx;
	}
	else if (frame->side == 1 && frame->raydiry > 0)
	{
		frame->floorx = frame->mapx + m->wallx;
		frame->floory = frame->mapy;
	}
	else
	{
		frame->floorx = frame->mapx + m->wallx;
		frame->floory = frame->mapy + 1;
	}
}

void	calc_perp_wall(t_mlx *m, t_frame *frame)
{
	if (frame->side == 0)
		frame->walldist = (frame->mapx - m->posx +
		(1 - frame->changex) / 2) / frame->raydirx;
	else
		frame->walldist = (frame->mapy - m->posy +
		(1 - frame->changey) / 2) / frame->raydiry;
	if (frame->side == 0)
		m->wallx = m->posy + frame->walldist * frame->raydiry;
	else if (frame->side == 1)
		m->wallx = m->posx + frame->walldist * frame->raydirx;
	if (frame->walldist < 0.01)
		frame->walldist += 0.01;
}

void	calc_textures(t_mlx *m, t_frame *frame)
{
	m->wallx -= floor((m->wallx));
	m->texx = (int)(m->wallx * (double)64);
	if (frame->side == 0 && frame->raydirx > 0)
		m->texx = 64 - m->texx - 1;
	if (frame->side == 1 && frame->raydiry < 0)
		m->texx = 64 - m->texx - 1;
	m->texnum = m->map[frame->mapx][frame->mapy] - 1;
}
