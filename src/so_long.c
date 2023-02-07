/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 08:47:26 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/07 13:24:36 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	main(int argc, char **argv)
{
	int		fd;
	t_data	d;

	argc = 1;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_exit(0, "ERROR\nNo map provided!\n"));
	if (!read_map(fd, &d, argv))
		return (0);
	init_data(&d);
	if (!map_checker(&d) || !d.mlx)
		return (0);
	print_map(&d);
	mlx_key_hook(d.mlx, &mover, &d);
	mlx_loop(d.mlx);
	mlx_close_window(d.mlx);
	mlx_terminate(d.mlx);
}