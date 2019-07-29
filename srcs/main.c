/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/04 15:43:25 by knguyen-          #+#    #+#             */
/*   Updated: 2019/05/25 21:18:06 by knguyen-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_mlx m;

	if (argc != 2)
		return (-1);
	setup(&m);
	readfile(argv[1], &m);
	floodfill(&m, m.posy, m.posx);
	fixmap(&m);
	setup_textures(&m);
	m.frk = fork();
	if (m.frk < 0)
		exit(-1);
	else if (m.frk == 0)
	{
		while (42)
			execlp("afplay", "afplay", "./LunarDial.mp3", 0);
	}
	else
		hooks(126, &m);
	return (0);
}
