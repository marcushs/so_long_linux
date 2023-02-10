/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 07:27:23 by hleung            #+#    #+#             */
/*   Updated: 2023/01/17 17:18:07 by hleung           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total_size;
	size_t	i;

	if (count != 0 && size > SIZE_MAX / count)
		return (NULL);
	total_size = count * size;
	mem = (char *)malloc(total_size);
	if (!mem)
		return (NULL);
	i = 0;
	while (i < total_size)
	{
		((char *)mem)[i] = 0;
		i++;
	}
	return (mem);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new_str;
	size_t	size;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = (char *)ft_calloc(1, 1);
		if (!s1)
			return (NULL);
	}
	size = ft_strlen(s1) + ft_strlen(s2);
	new_str = (char *)ft_calloc((size + 1), sizeof(char));
	if (!new_str || !s2)
		return (free(s1), s1 = NULL, NULL);
	i = 0;
	while (s1[i])
	{
		new_str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
		new_str[i++] = s2[j++];
	return (free(s1), s1 = NULL, new_str);
}

int	ft_strchr_gnl(char *s, int c)
{
	int	len;
	int	i;

	if (!s)
		return (0);
	len = ft_strlen(s);
	i = 0;
	while (i <= len)
	{
		if (s[i] == (unsigned char)c)
			return (1);
		i++;
	}
	return (0);
}
