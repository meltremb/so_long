/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:39:25 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/07 13:24:16 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line_bonus.h"

/* for the other functions mostly */
int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/* points the first instance of \n in the doc */
char	*ft_strchr(char *s, int endline)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (endline == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char)endline)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

/* joins the doc with a string of the right length for
 * the buffer and returns a copy */

char	*ft_strjoin(char *doc_str, char *bufferlen)
{
	char	*str;
	int		i;
	int		j;

	if (!doc_str)
	{
		doc_str = malloc(1 * sizeof(char));
		doc_str[0] = '\0';
	}
	if (!doc_str || !bufferlen)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(doc_str) + ft_strlen(bufferlen))
				+ 1));
	if (!str)
		return (NULL);
	i = -1;
	j = 0;
	if (doc_str)
		while (doc_str[++i] != '\0')
			str[i] = doc_str[i];
	while (bufferlen[j] != '\0')
		str[i++] = bufferlen[j++];
	str[ft_strlen(doc_str) + ft_strlen(bufferlen)] = '\0';
	free(doc_str);
	return (str);
}

/* deletes the first line of the document to get the next one after */
char	*delete_first_line(char *doc)
{
	int		i;
	int		j;
	char	*deldoc;

	i = 0;
	while (doc[i] && doc[i] != '\n')
		i++;
	if (!doc[i])
	{
		free(doc);
		return (NULL);
	}
	deldoc = malloc(sizeof(char) * (ft_strlen(doc) - i + 1));
	if (!deldoc)
		return (NULL);
	i++;
	j = 0;
	while (doc[i])
		deldoc[j++] = doc[i++];
	deldoc[j] = '\0';
	free(doc);
	return (deldoc);
}

char	*get_line(char *doc)
{
	char	*line;
	int		i;

	i = 0;
	if (!*doc)
		return (NULL);
	while (doc[i] != '\n' && doc[i])
		i++;
	line = malloc(sizeof(char) * (i + 1 + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (doc[i] != '\n' && doc[i])
	{
		line[i] = doc[i];
		i++;
	}
	if (doc[i] == '\n')
	{
		line[i] = doc[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}
