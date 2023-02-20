/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:47:26 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/20 13:59:28 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	d;

	ft_null(&d);
	if (argc != 2)
		ft_exit(&d, 0, "ERROR\nNo map provided!");
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_exit(&d, 0, "ERROR\nYour dumbass can't spell!\n");
	if (ber_check(argv[1]) == 0)
		ft_exit(&d, 0, "ERROR\nThe map isn't a .ber file!");
	if (!read_map(fd, &d, argv))
		return (0);
	init_data(&d);
	if (!map_checker(&d) || !d.mlx)
		return (0);
	print_map(&d);
	mlx_key_hook(d.mlx, &mover, &d);
	mlx_loop(d.mlx);
}
