/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:01:52 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/22 13:03:09 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	elem_counter(t_data *d)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < d->max_y)
	{
		x = -1;
		while (++x < d->max_x)
		{
			if (d->map_copy[y][x] == 'E' || d->map_copy[y][x] == 'e')
				d->exit_count++;
			if (d->map_copy[y][x] == 'P' || d->map_copy[y][x] == 'p')
				d->start_count++;
			if (d->map_copy[y][x] == 'C' || d->map_copy[y][x] == 'c')
				d->chest_count++;
		}
	}
}

int	map_shape_check(t_data *d)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < d->max_y)
	{
		x = -1;
		while (++x < d->max_x)
		{
			if ((d->map_copy[0][x] != '1')
				|| (d->map_copy[d->max_y - 1][x] != '1'))
				return (0);
			if ((d->map_copy[y][0] != '1')
				|| (d->map_copy[y][d->max_x - 1] != '1'))
				return (0);
			if ((ft_strlen(d->map[y]) - 1) != d->max_x)
				return (0);
		}
	}
	return (1);
}

void	flood_fill(t_data *d, int x, int y)
{
	if (d->map_copy[y][x] == '0' || d->map_copy[y][x] == 'P'
		|| d->map_copy[y][x] == 'C' || d->map_copy[y][x] == 'E')
	{
		d->map_copy[y][x] = '2';
		flood_fill(d, x + 1, y);
		flood_fill(d, x - 1, y);
		flood_fill(d, x, y + 1);
		flood_fill(d, x, y - 1);
	}
}

int	valid_path(t_data *d)
{
	size_t	x;
	size_t	y;

	init_start_pos(d);
	x = d->player_x / d->texture_size;
	y = d->player_y / d->texture_size;
	flood_fill(d, x, y);
	if (check_for(d, 'C') || check_for(d, 'E')
		|| check_for(d, 'c') || check_for(d, 'e'))
		return (0);
	return (1);
}

int	map_checker(t_data *d)
{
	elem_counter(d);
	if (d->start_count != 1)
		ft_exit(d, 0, "ERROR\nWrong amount of starting positions\n");
	else if (d->exit_count != 1)
		ft_exit(d, 0, "ERROR\nWrong amount of exits\n");
	else if (d->chest_count < 1)
		ft_exit(d, 0, "ERROR\nYou don't have collectibles\n");
	else if (d->max_y >= 15 || d->max_x >= 19)
		ft_exit(d, 0, "ERROR\nYour map exceeds the boundaries of the screen\n");
	else if (!is_valid_char(d))
		ft_exit(d, 0, "ERROR\nNon-valid item detected\n");
	else if (!map_shape_check(d))
		ft_exit(d, 0, "ERROR\nYour map isn't closed\n");
	else if (!valid_path(d))
		ft_exit(d, 0, "ERROR\nNo valid exit path\n");
	return (1);
}
