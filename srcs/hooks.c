/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 02:50:27 by jolam             #+#    #+#             */
/*   Updated: 2019/05/23 03:08:00 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int	redraw(t_mlx *m)
{
	mlx_clear_window(m->mlx_ptr, m->win_ptr);
	drawframe(m);
	return (0);
}

int	closep(t_mlx *m)
{
	kill(m->frk, SIGTSTP);
	exit(0);
	return (0);
}

int	keyhandle(int key, t_mlx *m)
{
	mlx_hook(m->win_ptr, 3, 0, hooks, m);
	if (key == 53)
	{
		kill(m->frk, SIGTSTP);
		exit(0);
	}
	else if (key == 126 || key == 13)
		mlx_loop_hook(m->mlx_ptr, forward, m);
	else if (key == 125 || key == 1)
		mlx_loop_hook(m->mlx_ptr, back, m);
	else if (key == 123 || key == 0)
		mlx_loop_hook(m->mlx_ptr, leftstrafe, m);
	else if (key == 124 || key == 2)
		mlx_loop_hook(m->mlx_ptr, rightstrafe, m);
	else if (key == 12 || key == 6)
		mlx_loop_hook(m->mlx_ptr, left, m);
	else if (key == 14 || key == 7)
		mlx_loop_hook(m->mlx_ptr, right, m);
	return (0);
}

int	hooks(int key, t_mlx *m)
{
	if (key == 53)
		exit(0);
	mlx_hook(m->win_ptr, 2, 0, keyhandle, m);
	mlx_hook(m->win_ptr, 17, (1L << 17), closep, m);
	if (key == 126 || key == 125 || key == 123 || key == 124 ||
			key == 13 || key == 1 || key == 2 || key == 0 ||
			key == 12 || key == 6 || key == 14 || key == 7)
		mlx_loop_hook(m->mlx_ptr, redraw, m);
	mlx_loop(m->mlx_ptr);
	return (0);
}
