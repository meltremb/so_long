/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:57:44 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/20 11:39:57 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_map(t_data *d)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < d->max_y)
	{
		x = -1;
		while (++x < d->max_x)
		{
			print_background(d, x, y);
			print_foreground(d, x, y);
		}
	}
	mlx_image_to_window(d->mlx, d->dumbass, d->player_x, d->player_y);
}

void	print_background(t_data *d, int x, int y)
{
	if (d->map[y][x] == '1')
		mlx_image_to_window(d->mlx, d->wall,
			x * d->texture_size, y * d->texture_size);
	else
		mlx_image_to_window(d->mlx, d->floor,
			x * d->texture_size, y * d->texture_size);
}

void	print_foreground(t_data *d, int x, int y)
{
	if (d->map[y][x] == 'C')
		mlx_image_to_window(d->mlx, d->chest,
			x * d->texture_size, y * d->texture_size);
	if (d->map[y][x] == 'E')
		mlx_image_to_window(d->mlx, d->door,
			x * d->texture_size, y * d->texture_size);
}
