/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:40 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/07 11:34:11 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	read_map(int fd, t_data *d, char **argv)
{
	int		i;

	d->max_x = ft_strlen(get_next_line(fd)) - 1;
	i = 1;
	while (get_next_line(fd) != NULL)
		d->max_y = ++i;
	close(fd);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	d->map = ft_calloc((d->max_y + 1), sizeof(char *));
	d->map_copy = ft_calloc((d->max_y + 1), sizeof(char *));
	while (++i < d->max_y)
	{
		d->map[i] = get_next_line(fd);
		if (ft_strlen(d->map[i]) == d->max_x && d->map[i][d->max_x] != '\n')
			d->map[i] = ft_add_newline(d->map[i], "\n");
		if ((ft_strlen(d->map[i])) - 1 != d->max_x)
			return (ft_exit(0, "ERROR\nThe map isn't a rectangle!\n"));
		d->map_copy[i] = ft_strdup(d->map[i]);
	}
	close(fd);
	return (1);
}