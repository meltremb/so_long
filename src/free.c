/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:29:01 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/27 09:23:15 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_null(t_data *d)
{
	d->mlx = NULL;
	d->floor = NULL;
	d->wall = NULL;
	d->dumbass = NULL;
	d->chest = NULL;
	d->door = NULL;
	d->map = NULL;
	d->map_copy = NULL;
}

void	*free_and_null(void *ptr)
{
	if (ptr)
		free(ptr);
	return (NULL);
}

void	ft_free_image(mlx_t *mlx, mlx_image_t *image)
{
	if (image)
		mlx_delete_image(mlx, image);
}

void	ft_free_all(t_data *d)
{
	size_t	i;

	ft_free_image(d->mlx, d->floor);
	ft_free_image(d->mlx, d->wall);
	ft_free_image(d->mlx, d->dumbass);
	ft_free_image(d->mlx, d->chest);
	ft_free_image(d->mlx, d->door);
	i = -1;
	while (d->map && d->map[++i])
		d->map[i] = free_and_null(d->map[i]);
	i = -1;
	while (d->map_copy && d->map_copy[++i])
		d->map_copy[i] = free_and_null(d->map_copy[i]);
	d->map = free_and_null(d->map);
	d->map_copy = free_and_null(d->map_copy);
	if (d->mlx)
		mlx_terminate(d->mlx);
}
