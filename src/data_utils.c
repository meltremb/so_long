/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:23:38 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/07 13:52:52 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

mlx_image_t	*make_image(t_data *d, char *path)
{
	mlx_image_t	*image;
	xpm_t		*xpm;

	xpm = mlx_load_xpm42(path);
	image = mlx_texture_to_image(d->mlx, &xpm->texture);
	mlx_delete_xpm42(xpm);
	return (image);
}

int	check_for(t_data *d, char c)
{
	int		x;
	int		y;

	y = -1;
	while (++y < d->max_y)
	{
		x = -1;
		while (++x < d->max_x)
		{
			if (d->map_copy[y][x] == c)
				return (1);
		}
	}
	return (0);
}

int	ft_exit(int exit_state, char *message)
{
	int		i;

	i = -1;
	while (message[++i] != '\0')
		write (1, &message[i], 1);
	if (exit_state == 0)
		return (0);
	return (1);
}

void	init_data(t_data *d)
{
	d->texture_size = 128;
	d->nb_moves = 0;
	d->chest_count = 0;
	d->exit_count = 0;
	d->start_count = 0;
	d->width = d->texture_size * d->max_x;
	d->height = d->texture_size * d->max_y;
	d->mlx = mlx_init(d->width, d->height, "The Lost Dumbass", false);
	d->floor = make_image(d, "assets/floor.xpm42");
	d->wall = make_image(d, "assets/wall.xpm42");
	d->dumbass = make_image(d, "assets/dumbass.xpm42");
	d->chest = make_image(d, "assets/chest.xpm42");
	d->door = make_image(d, "assets/door.xpm42");
}
