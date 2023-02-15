/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 11:45:43 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/15 10:34:20 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_bzero(void *s, size_t n)
{
	char	*clean;

	clean = s;
	while (n--)
		*clean++ = 0;
}

char	*ft_strdup(char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = malloc((ft_strlen(s1) + 1) * (sizeof(char)));
	if (!ptr)
		return (NULL);
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, count * size);
	return (ptr);
}

int	is_valid_char(t_data *d)
{
	int		x;
	int		y;
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
	str[i] = '\0';
	return (str);
}
