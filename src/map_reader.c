/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 12:36:40 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/15 11:45:30 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*temp;

	temp = s;
	while (*s)
		s++;
	while (s >= temp)
		if (*s-- == (char) c)
			return ((char *)s + 1);
	return (NULL);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

int	ber_check(char *map_name)
{
	char	*dot;

	dot = ft_strrchr(map_name, '.');
	if (ft_strncmp(dot, ".ber", 4) == 0)
			return (1);
	//if (map_name[i - 1] == 'r' && map_name[i - 2] == 'e'
	//	&& map_name[i - 3] == 'b' && map_name[i - 4] == '.')
	//	return (1);
	return (0);
}

int	read_map(int fd, t_data *d, char **argv)
{
	int		i;

	d->max_x = ft_strlen(get_next_line(fd)) - 1;
	i = 1;
	while (get_next_line(fd) != NULL)
		d->max_y = ++i;
	close(fd);
	i = -1;
	fd = open(argv[1], O_RDONLY);
	d->map = ft_calloc((d->max_y + 1), sizeof(char *));
	d->map_copy = ft_calloc((d->max_y + 1), sizeof(char *));
	while (++i < d->max_y)
	{
		d->map[i] = get_next_line(fd);
		if (ft_strlen(d->map[i]) == d->max_x && d->map[i][d->max_x] != '\n')
			d->map[i] = ft_add_newline(d->map[i], "\n");
		if ((ft_strlen(d->map[i])) - 1 != d->max_x)
			ft_exit(d, 0, "ERROR\nThe map isn't a rectangle!\n");
		if (ft_strlen(d->map[i]) < 3 || d->max_y < 3)
			ft_exit(d, 0, "ERROR\nYour map straight up sucks!\n");
		d->map_copy[i] = ft_strdup(d->map[i]);
	}
	close(fd);
	return (1);
}
