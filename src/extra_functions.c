/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:45:43 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/20 13:39:35 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	is_valid_char(t_data *d)
{
	size_t	x;
	size_t	y;
	char	c;

	y = -1;
	while (++y < d->max_y)
	{
		x = -1;
		while (++x < d->max_x)
		{
			c = d->map_copy[y][x];
			if (c == '0' || c == '1' || c == 'E' || c == 'e' || c == 'P'
				|| c == 'p' || c == 'C' || c == 'c' || c == '\n')
				continue ;
			else
				return (0);
		}
	}
	return (1);
}

char	*ft_add_newline(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	free(s1);
	str[i] = '\0';
	return (str);
}
