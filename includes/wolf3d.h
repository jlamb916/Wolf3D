/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:30:05 by knguyen-          #+#    #+#             */
/*   Updated: 2019/05/23 03:08:11 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# define WIDTH 1200
# define HEIGHT 900

# include "libft.h"
# include <stdlib.h>
# include "mlx.h"
# include <math.h>
# include <time.h>
# include <fcntl.h>
# include <signal.h>
# include <unistd.h>

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	int				bpp;
	int				endian;
	int				linesize;
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			dirxsave;
	double			planexsave;
	double			planex;
	double			planey;
	int				**map;
	char			*data;
	double			frames;
	double			posxs;
	double			posys;
	pid_t			frk;
	int				i;
	int				j;
	int				flag;
	int				mapw;
	int				maph;
	double			rotspeed;
	double			movespeed;
	char			*tex[10];
	void			*xpm;
	int				ts;
	int				texnum;
	unsigned int	color;
	int				texx;
	int				texy;
	double			wallx;
}					t_mlx;

typedef struct		s_reader
{
	int				fd;
	int				t;
	char			*line;
	char			**temp;
}					t_reader;

typedef struct		s_frame
{
	double			camerax;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	double			sidedistx;
	double			sidedisty;
	double			deltax;
	double			deltay;
	double			walldist;
	double			floorx;
	double			floory;
	double			playerdist;
	double			curdist;
	double			weight;
	double			curfloorx;
	double			curfloory;
	int				changex;
	int				changey;
	int				wall;
	int				side;
	int				lineh;
	int				drawstart;
	int				drawend;
}					t_frame;

void				calc_perp_wall(t_mlx *m, t_frame *frame);
void				calc_textures(t_mlx *m, t_frame *frame);
void				calc_floor_dist(t_mlx *m, t_frame *frame);
void				draw_wall(t_mlx *m, t_frame *frame, int x);
void				draw_floor_ceiling(t_mlx *m, t_frame *frame, int x);
void				calc_wall_hit(t_mlx *m, t_frame *frame);
void				init_ray(t_mlx *m, t_frame *f, int x);
void				calc_dist(t_mlx *m, t_frame *frame);
int					redraw(t_mlx *m);
void				drawframe(t_mlx *m);
int					hooks(int key, t_mlx *m);
int					keyhandle(int key, t_mlx *m);
int					forward(t_mlx *m);
int					back(t_mlx *m);
int					right(t_mlx *m);
int					left(t_mlx *m);
int					leftstrafe(t_mlx *m);
int					rightstrafe(t_mlx *m);
void				fixmap(t_mlx *m);
int					floodfill(t_mlx *m, int x, int y);
void				readfile(char *file, t_mlx *m);
void				setup(t_mlx *m);
void				setup_textures(t_mlx *m);

#endif
