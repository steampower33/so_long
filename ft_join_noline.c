/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_noline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:40:02 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/24 17:09:53 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strcat(char *s, char *s1, char *s2)
{
	size_t	idx;
	size_t	s2_len;

	idx = 0;
	while (idx < ft_strlen(s1))
	{
		s[idx] = s1[idx];
		idx++;
	}
	if (s2[ft_strlen(s2) - 1] == '\n')
		s2_len = ft_strlen(s2) - 1;
	else
		s2_len = ft_strlen(s2);
	idx = 0;
	while (idx < s2_len)
	{
		s[ft_strlen(s1) + idx] = s2[idx];
		idx++;
	}
	s[ft_strlen(s1) + idx] = '\0';
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (s);
}

char	*ft_join_noline(char *s1, char *s2)
{
	size_t	len;
	char	*s;

	if (!ft_strlen(s1) && !ft_strlen(s2))
		return ((char *)ft_calloc(sizeof(char), 1));
	if (s2[ft_strlen(s2) - 1] == '\n')
		len = ft_strlen(s1) + ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2) + 1;
	s = (char *) malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	return (ft_strcat(s, s1, s2));
}
