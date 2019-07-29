/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 03:08:03 by jolam             #+#    #+#             */
/*   Updated: 2019/05/23 03:09:42 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		setup(t_mlx *m)
{
	m->rotspeed = 0.05;
	m->movespeed = 0.05;
	m->dirx = -1;
	m->diry = 0;
	m->planex = 0;
	m->planey = 0.66;
	m->bpp = 8;
	m->endian = 1;
	m->linesize = 1 * WIDTH;
	m->mlx_ptr = mlx_init();
	m->win_ptr = mlx_new_window(m->mlx_ptr, WIDTH, HEIGHT, "Wolf");
	m->img_ptr = mlx_new_image(m->mlx_ptr, WIDTH, HEIGHT);
	m->data = mlx_get_data_addr(m->img_ptr, &(m->bpp),
		&(m->linesize), &(m->endian));
}

static void	setup_textures2(t_mlx *m)
{
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/redbrick.xpm",
		&m->ts, &m->ts);
	m->tex[6] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/greystone.xpm",
		&m->ts, &m->ts);
	m->tex[7] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/pillar.xpm",
		&m->ts, &m->ts);
	m->tex[8] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/green.xpm",
		&m->ts, &m->ts);
	m->tex[9] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
}

void		setup_textures(t_mlx *m)
{
	m->ts = 64;
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/wood.xpm",
		&m->ts, &m->ts);
	m->tex[0] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/bluestone.xpm",
		&m->ts, &m->ts);
	m->tex[1] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/colorstone.xpm",
		&m->ts, &m->ts);
	m->tex[2] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/eagle.xpm",
		&m->ts, &m->ts);
	m->tex[3] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/purplestone.xpm",
		&m->ts, &m->ts);
	m->tex[4] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	m->xpm = mlx_xpm_file_to_image(m->mlx_ptr, "./tex/mossy.xpm",
		&m->ts, &m->ts);
	m->tex[5] = mlx_get_data_addr(m->xpm, &m->bpp, &m->linesize, &m->endian);
	setup_textures2(m);
}
