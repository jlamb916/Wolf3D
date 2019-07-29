/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: knguyen- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 17:21:20 by knguyen-          #+#    #+#             */
/*   Updated: 2019/05/23 01:16:34 by jolam            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	append_line(char **ldt, char **line)
{
	int		i;
	char	*temp;

	i = 0;
	while ((*ldt)[i] != '\n' && (*ldt)[i] != '\0')
		i++;
	if ((*ldt)[i] == '\n')
	{
		*line = ft_strsub(*ldt, 0, i);
		temp = ft_strdup(&((*ldt)[i + 1]));
		free(*ldt);
		*ldt = temp;
		if (!(*ldt)[0])
			ft_strdel(ldt);
	}
	else
	{
		*line = ft_strdup(*ldt);
		ft_strdel(ldt);
	}
	return (1);
}

static int	ret_check(char **ldt, char **line, int ret, int fd)
{
	if (ret < 0)
		return (-1);
	else if (ret == 0 && !ldt[fd])
		return (0);
	else
		return (append_line(&ldt[fd], line));
}

int			get_next_line(const int fd, char **line)
{
	static char	*ldt[4864];
	char		buffer[BUFF_SIZE + 1];
	int			ret;
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[ret] = '\0';
		if (!ldt[fd])
			ldt[fd] = ft_strdup(buffer);
		else
		{
			temp = ft_strjoin(ldt[fd], buffer);
			free(ldt[fd]);
			ldt[fd] = temp;
		}
		if (ft_strchr(ldt[fd], '\n'))
			break ;
	}
	return (ret_check(ldt, line, ret, fd));
}
