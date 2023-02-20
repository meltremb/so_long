/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:00 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/15 12:39:08 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	print_nb_moves(t_data *d)
{
	if (d->dumbass->instances->x != d->player_x
		|| d->dumbass->instances->y != d->player_y)
	{
		d->nb_moves++;
		printf("number of moves: %d\n", d->nb_moves);
	}
}
