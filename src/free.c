/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 14:29:01 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/15 10:21:15 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_and_null(void *ptr)
{
	if (ptr)
		free(ptr);
	ptr = NULL;
}

void	ft_free_all(t_data *d)
{
	int	i;

	i = -1;
	while (++i < d->max_y)
	{
		free_and_null(d->map[i]);
		free_and_null(d->map_copy[i]);
	}
	mlx_delete_image(d->mlx, d->floor);
	mlx_delete_image(d->mlx, d->wall);
	mlx_delete_image(d->mlx, d->dumbass);
	mlx_delete_image(d->mlx, d->chest);
	mlx_delete_image(d->mlx, d->door);
	free_and_null(d->map);
	free_and_null(d->map_copy);
	mlx_terminate(d->mlx);
}
