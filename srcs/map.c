/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolam <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/23 02:57:46 by jolam             #+#    #+#             */
/*   Updated: 2019/05/23 03:03:37 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	update_pos(t_mlx *m, int j, int i)
{
	if (m->map[j][i] == 9)
	{
		if (m->flag >= 1)
			ft_putstrexit("Error: Map has more than 1 start");
		m->posx = j;
		m->posy = i;
		m->flag++;
		m->map[j][i] = 0;
	}
	else if (m->map[j][i] > 9 || m->map[j][i] < 0)
		ft_putstrexit("Error: Map has invalid wall number");
}

static void	validate(t_mlx *m)
{
	int i;
	int j;
	int c;

	c = 0;
	m->flag = 0;
	i = -1;
	while (++i < m->mapw)
	{
		j = -1;
		while (++j < m->maph)
		{
			update_pos(m, j, i);
		}
	}
	if (m->flag == 0)
		ft_putstrexit("Error: Map has no start");
}

static void	fillmap(t_mlx *m, t_reader *r, char *file)
{
	m->i = -1;
	while (r->temp[++m->i])
		free(r->temp[m->i]);
	free(r->temp);
	r->fd = open(file, O_RDONLY);
	m->i = 0;
	while (get_next_line(r->fd, &r->line) > 0)
	{
		r->temp = ft_strsplit(r->line, ' ');
		free(r->line);
		m->j = -1;
		while (r->temp[++m->j])
			m->map[m->i][m->j] = ft_atoi(r->temp[m->j]);
		m->j != m->mapw ? ft_putstrexit("Invalid Map: Map not rectangular") : 0;
		m->i++;
		m->j = -1;
		while (r->temp[++m->j])
			free(r->temp[m->j]);
		free(r->temp);
	}
	close(r->fd);
	validate(m);
}

void		readfile(char *file, t_mlx *m)
{
	t_reader	r;

	r.t = -1;
	m->mapw = 0;
	if ((r.fd = open(file, O_DIRECTORY)) > 0)
		ft_putstrexit("Error: Is directory");
	if ((r.fd = open(file, O_RDONLY)) < 0)
		ft_putstrexit("Error: No File");
	get_next_line(r.fd, &r.line);
	r.temp = ft_strsplit(r.line, ' ');
	free(r.line);
	while (r.temp[m->mapw])
		m->mapw++;
	m->maph = 1;
	while ((get_next_line(r.fd, &r.line)) > 0 && m->maph++)
		free(r.line);
	m->map = (int **)ft_memalloc(sizeof(int *) * m->maph);
	while (++r.t < m->maph)
		m->map[r.t] = (int *)ft_memalloc(sizeof(int) * m->mapw);
	close(r.fd);
	fillmap(m, &r, file);
}
