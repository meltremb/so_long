/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 14:26:27 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/07 13:24:17 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*read_fd(int fd, char *doc)
{
	char	*bufferlen;
	int		fdret;

	bufferlen = malloc(sizeof(char) * (1));
	if (!bufferlen)
		return (NULL);
	fdret = 1;
	while (fdret != 0 && !ft_strchr(doc, '\n'))
	{
		fdret = read(fd, bufferlen, 1);
		if (fdret == -1)
		{
			free(bufferlen);
			return (NULL);
		}
		bufferlen[fdret] = '\0';
		doc = ft_strjoin(doc, bufferlen);
	}
	free(bufferlen);
	return (doc);
}

char	*get_next_line(int fd)
{
	static char	*doc[OPEN_MAX];
	char		*line;

	if (fd < 0 || read(fd, 0, 0) < 0)
		return (0);
	doc[fd] = read_fd(fd, doc[fd]);
	line = get_line(doc[fd]);
	doc[fd] = delete_first_line(doc[fd]);
	return (line);
}
