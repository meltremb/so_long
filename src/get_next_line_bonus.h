/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meltremb <meltremb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:08 by meltremb          #+#    #+#             */
/*   Updated: 2023/02/07 13:23:17 by meltremb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

char	*get_next_line(int fd);
char	*read_fd(int fd, char *doc);
int		ft_strlen(char *s);
char	*ft_strchr(char *doc, int endline);
char	*ft_strjoin(char *doc, char *bufferlen);
char	*delete_first_line(char *doc);
char	*get_line(char *doc);

#endif
