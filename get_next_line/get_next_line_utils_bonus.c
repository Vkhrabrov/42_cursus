/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhrabro <vkhrabro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 20:03:33 by vkhrabro          #+#    #+#             */
/*   Updated: 2023/04/23 20:42:40 by vkhrabro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *c)
{
	size_t	i;

	i = 0;
	if (*c != '\0')
	{
		while (*c)
		{	
			i++;
			c++;
		}
	}
	return (i);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (src[n] != '\0')
		n++;
	i = 0;
	if (dstsize < 1)
		return (n);
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dest[i] = src[i];
		i++;
	}
		dest[i] = '\0';
	return (n);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0')
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	size_t	i;

	i = ft_strlen(s1) + 1;
	s2 = (char *)malloc(i);
	if (s2 == NULL)
		return (s2);
	if (s1 != NULL)
		ft_strlcpy(s2, s1, i);
	return (s2);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	char	*new;
	int		s1_was_allocated;

	s1_was_allocated = 0;
	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
		s1_was_allocated = 1;
	}
	s3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s3)
		return (NULL);
	new = s3;
	while (*s1 != '\0')
		*s3++ = *s1++;
	while (*s2 != '\0')
		*s3++ = *s2++;
	*s3++ = '\0';
	if (s1_was_allocated)
		free(s1);
	return (new);
}
