/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_frame.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 02:40:51 by jolam             #+#    #+#             */
/*   Updated: 2019/05/25 21:29:53 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	drawframe(t_mlx *m)
{
	t_frame		frame;
	int			x;

	x = 0;
	while (x < WIDTH)
	{
		init_ray(m, &frame, x);
		calc_dist(m, &frame);
		calc_wall_hit(m, &frame);
		calc_perp_wall(m, &frame);
		calc_textures(m, &frame);
		draw_wall(m, &frame, x);
		calc_floor_dist(m, &frame);
		draw_floor_ceiling(m, &frame, x);
		x++;
	}
	mlx_put_image_to_window(m->mlx_ptr, m->win_ptr, m->img_ptr, 0, 0);
}

void	init_ray(t_mlx *m, t_frame *frame, int x)
{
	frame->camerax = 2 * x / (double)WIDTH - 1;
	frame->raydirx = m->dirx + m->planex * frame->camerax;
	frame->raydiry = m->diry + m->planey * frame->camerax;
	frame->mapx = (int)m->posx;
	frame->mapy = (int)m->posy;
	frame->deltax = fabs(1 / frame->raydirx);
	frame->deltay = fabs(1 / frame->raydiry);
	frame->wall = 0;
}

void	draw_wall(t_mlx *m, t_frame *frame, int x)
{
	int d;

	frame->lineh = (int)(HEIGHT / frame->walldist);
	frame->drawstart = -frame->lineh / 2 + HEIGHT / 2;
	if (frame->drawstart < 0)
		frame->drawstart = 0;
	frame->drawend = frame->lineh / 2 + HEIGHT / 2;
	if (frame->drawend >= HEIGHT)
		frame->drawend = HEIGHT;
	frame->drawstart--;
	while (++frame->drawstart < frame->drawend)
	{
		d = frame->drawstart * 256 - HEIGHT * 128 + frame->lineh * 128;
		m->texy = ((d * 64) / frame->lineh) / 256;
		m->color = ((unsigned int **)m->tex)[m->texnum][64
			* m->texy + m->texx];
		if (frame->side == 1)
			m->color = (m->color >> 1) & 8355711;
		((unsigned int *)m->data)[x + (WIDTH * frame->drawstart)] = m->color;
	}
}

void	draw_floor_ceiling(t_mlx *m, t_frame *frame, int x)
{
	int t;

	frame->playerdist = 0;
	if (frame->drawend < 0)
		frame->drawend = HEIGHT;
	t = frame->drawend - 1;
	while (++t < HEIGHT)
	{
		frame->curdist = HEIGHT / (2.0 * t - HEIGHT);
		frame->weight = (frame->curdist - frame->playerdist) /
			(frame->walldist - frame->playerdist);
		frame->curfloorx = frame->weight * frame->floorx +
			(1.0 - frame->weight) * m->posx;
		frame->curfloory = frame->weight * frame->floory +
			(1.0 - frame->weight) * m->posy;
		m->texx = (int)(frame->curfloorx * 64) % 64;
		m->texy = (int)(frame->curfloory * 64) % 64;
		m->color = ((unsigned int **)m->tex)[5][64 *
			m->texx + m->texy];
		((unsigned int *)m->data)[x + (WIDTH * t)] = m->color;
		((unsigned int *)m->data)[x + (WIDTH * (HEIGHT - t))] = m->color / 2;
	}
}
