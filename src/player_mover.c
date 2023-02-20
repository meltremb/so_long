/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mover.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:34:16 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/20 11:41:54 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	init_start_pos(t_data *d)
{
	size_t	x;
	size_t	y;

	y = -1;
	while (++y < d->max_y)
	{
		x = -1;
		while (++x < d->max_x)
		{
			if (d->map[y][x] == 'P')
			{
				d->player_x = x * d->texture_size;
				d->player_y = y * d->texture_size;
				return (1);
			}
		}
	}
	return (0);
}

int	is_movable(mlx_key_data_t keydata, t_data *d)
{
	size_t	x;
	size_t	y;

	x = d->player_x / d->texture_size;
	y = d->player_y / d->texture_size;
	if (keydata.key == MLX_KEY_W)
		if (d->map[y - 1][x] == '1')
			return (0);
	if (keydata.key == MLX_KEY_S)
		if (d->map[y + 1][x] == '1')
			return (0);
	if (keydata.key == MLX_KEY_A)
		if (d->map[y][x - 1] == '1')
			return (0);
	if (keydata.key == MLX_KEY_D)
		if (d->map[y][x + 1] == '1')
			return (0);
	return (1);
}

void	is_item_or_door(t_data *d)
{
	size_t	x;
	size_t	y;

	x = d->player_x / d->texture_size;
	y = d->player_y / d->texture_size;
	print_nb_moves(d);
	if (d->map[y][x] == 'C')
	{
		d->chest_count--;
		mlx_image_to_window(d->mlx, d->floor, d->player_x, d->player_y);
		mlx_delete_image(d->mlx, d->dumbass);
		d->dumbass = make_image(d, "assets/dumbass.xpm42");
		mlx_image_to_window(d->mlx, d->dumbass, d->player_x, d->player_y);
		d->map[y][x] = '0';
	}
	if (d->map[y][x] == 'E' && d->chest_count == 0)
		ft_exit(d, 1, "Congratulations!");
}

void	mover(mlx_key_data_t keydata, void *param)
{
	t_data	*d;

	d = param;
	if (keydata.action == MLX_PRESS)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
			ft_exit(d, 0, "Game closed\n");
		if (keydata.key == MLX_KEY_W && is_movable(keydata, d) != 0)
			d->player_y = d->player_y - d->texture_size;
		if (keydata.key == MLX_KEY_S && is_movable(keydata, d) != 0)
			d->player_y = d->player_y + d->texture_size;
		if (keydata.key == MLX_KEY_A && is_movable(keydata, d) != 0)
			d->player_x = d->player_x - d->texture_size;
		if (keydata.key == MLX_KEY_D && is_movable(keydata, d) != 0)
			d->player_x = d->player_x + d->texture_size;
		is_item_or_door(d);
	}
	d->dumbass->instances->x = d->player_x;
	d->dumbass->instances->y = d->player_y;
}
