/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:40 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/22 15:09:32 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ber_check(int fd, t_data *d, char *map_name)
{
	char	*dot;

	dot = ft_strrchr(map_name, '.');
	if (!dot || read(fd, 0, 0) == -1)
		ft_exit(d, 0, "ERROR\nNot an actual file\n");
	if (ft_strncmp(dot, ".ber", 5) == 0)
		return (1);
	return (0);
}

int	get_max(int fd, int i, t_data *d)
{
	char	*temp;
	int		len;

	temp = get_next_line(fd);
	len = ft_strlen(temp) - 1;
	if (len == -1)
		ft_exit(d, 0, "ERROR\nYour map is empty");
	d->max_x = len;
	while (temp)
	{
		d->max_y = ++i;
		free(temp);
		temp = get_next_line(fd);
	}
	close(fd);
	i = -1;
	return (i);
}

int	read_map(int fd, t_data *d, char **argv)
{
	size_t	i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	i = get_max(fd, i, d);
	fd = open(argv[1], O_RDONLY);
	d->map = ft_calloc((d->max_y + 1), sizeof(char *));
	d->map_copy = ft_calloc((d->max_y + 1), sizeof(char *));
	while (++i < d->max_y)
	{
		d->map[i] = get_next_line(fd);
		if (ft_strlen(d->map[i]) == d->max_x && d->map[i][d->max_x] != '\n')
			d->map[i] = ft_add_newline(d->map[i], "\n");
		if ((ft_strlen(d->map[i])) - 1 != d->max_x)
			ft_exit(d, 0, "ERROR\nThe map isn't a rectangle\n");
		if (ft_strlen(d->map[i]) < 3 || d->max_y < 3)
			ft_exit(d, 0, "ERROR\nYour map is too small\n");
		d->map_copy[i] = ft_strdup(d->map[i]);
	}
	close(fd);
	return (1);
}
