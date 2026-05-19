/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: soel-had <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 18:51:12 by soel-had          #+#    #+#             */
/*   Updated: 2025/11/27 12:21:30 by soel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# define MAX_FD 1024

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
int		new_line_found(char *line);
size_t	ft_strlen(char *s);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	*ft_memcpy(void *dest, void *src, size_t n);

#endif
