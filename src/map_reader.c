/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:40 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/22 12:28:49 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ber_check(t_data *d, char *map_name)
{
	char	*dot;

	dot = ft_strrchr(map_name, '.');
	if (!dot)
		ft_exit(d, 0, "ERROR\nYou sneaky little bastard, this ain't a file!\n");
	if (ft_strncmp(dot, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	get_max(int fd, int i, t_data *d)
{
	char	*temp;

	temp = get_next_line(fd);
	if (ft_strlen(temp) == 0)
		ft_exit(d, 0, "ERROR\nYou silly goose, that map is empty!\n");
	d->max_x = ft_strlen(temp) - 1;
	while (temp)
	{
		d->max_y = ++i;
		free(temp);
		temp = get_next_line(fd);
	}
	if (d->max_x < 0 || d->max_y < 0)
		ft_exit(d, 0, "ERROR\nYou silly goose, that map is empty!\n");
	close(fd);
	i = -1;
	return (i);
}

int	read_map(int fd, t_data *d, char **argv)
{
	size_t		i;

	i = 0;
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
			ft_exit(d, 0, "ERROR\nThe map isn't a rectangle!\n");
		if (ft_strlen(d->map[i]) < 3 || d->max_y < 3)
			ft_exit(d, 0, "ERROR\nYour map straight up sucks!\n");
		d->map_copy[i] = ft_strdup(d->map[i]);
	}
	close(fd);
	return (1);
}
