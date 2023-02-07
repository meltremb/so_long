/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 13:55:00 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/07 14:22:35 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	printc(char c)
{
	write(1, &c, 1);
	return (1);
}

int	printd(int nb)
{
	int	len;

	len = 0;
	if (nb == -2147483648)
	{
		printc('-');
		printc('2');
		nb = nb + 2000000000;
		nb = nb * -1;
		len = len + 2;
	}
	if (nb < 0)
	{
		printc('-');
		nb = nb * -1;
		len++;
	}
	if (nb > 9)
		len = len + printd(nb / 10);
	printc(nb % 10 + 48);
	return (++len);
}

void	print_nb_moves(t_data *d)
{
	if (d->dumbass->instances->x != d->player_x
		|| d->dumbass->instances->y != d->player_y)
	{
		d->nb_moves++;
		write (1, "number of moves: ", 17);
		printd(d->nb_moves);
		write (1, "\n", 1);
	}
}
