/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:11:29 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/15 08:52:55 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <memory.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../src/get_next_line_bonus.h"

typedef struct s_data
{
	int			texture_size;
	int			max_x;
	int			max_y;
	int			width;
	int			height;
	int			chest_count;
	int			exit_count;
	int			start_count;
	int			nb_moves;
	mlx_t		*mlx;
	char		**map;
	char		**map_copy;
	int			player_x;
	int			player_y;
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*dumbass;
	mlx_image_t	*chest;
	mlx_image_t	*door;
}				t_data;

void		ft_free(t_data *d);
mlx_image_t	*make_image(t_data *d, char *path);
void		print_background(t_data *d, int x, int y);
void		print_foreground(t_data *d, int x, int y);
void		mover(mlx_key_data_t keydata, void *param);
int			init_start_pos(t_data *d);
int			read_map(int fd, t_data *d, char **argv);
void		init_data(t_data *d);
int			is_movable(mlx_key_data_t keydata, t_data *d);
void		is_item_or_door(t_data *d);
void		elem_counter(t_data *d);
int			map_checker(t_data *d);
void		flood_fill(t_data *d, int x, int y);
int			valid_path(t_data *d);
void		print_map(t_data *d);
int			check_for(t_data *d, char c);
int			map_shape_check(t_data *d);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(char *s1);
void		*ft_calloc(size_t count, size_t size);
int			ft_exit(t_data *d, int exit_state, char *message);
int			is_valid_char(char c);
char		*ft_add_newline(char *s1, char *s2);
int			printc(char c);
int			printd(int nb);
void		print_nb_moves(t_data *d);
int			ber_check(char *map_name);

#endif