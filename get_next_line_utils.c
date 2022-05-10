/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbonaldi <bbonaldi@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 03:13:32 by coder             #+#    #+#             */
/*   Updated: 2022/05/10 01:20:55 by bbonaldi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
		i++;
	return (i);
}

int	ft_strchr(const char *s, int c, ssize_t *newline_position)
{
	*newline_position = 0;
	while (*s != (char)c)
	{
		if (!*s)
		{
			*newline_position = -1;
			return (0);
		}
		s++;
		(*newline_position) += 1;
	}
	return (1);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	qty_copied;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	qty_copied = 0;
	while (src[qty_copied] && (qty_copied < size - 1))
	{
		dst[qty_copied] = src[qty_copied];
		qty_copied++;
	}
	dst[qty_copied] = '\0';
	return (src_len);
}

char	*ft_strdup(const char *s)
{
	size_t	s_len;
	char	*duplicate_s;
	size_t	index;

	s_len = ft_strlen(s);
	duplicate_s = (char *)malloc(sizeof(*duplicate_s) * (s_len + 1));
	if (!duplicate_s)
		return (NULL);
	index = 0;
	while (s[index])
	{
		duplicate_s[index] = s[index];
		index++;
	}
	duplicate_s[index] = '\0';
	return (duplicate_s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	size_t	len;
	size_t	s1_len;
	size_t	s2_len;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	len = s1_len + s2_len;
	res = (char *) malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	free(s1 - s1_len);
	s1 = NULL;
	return (res - len);
}
