/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:19:44 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/04/23 01:29:33 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# include <stdlib.h>
# include <unistd.h>

size_t		ft_strlen(const char *c);
char		*ft_strchr(const char *str, int c);
char		*ft_strdup(const char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*get_next_line(int fd);
size_t		ft_strlcpy(char *dest, const char *src, size_t dstsize);

#endif
