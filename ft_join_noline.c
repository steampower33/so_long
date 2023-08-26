/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_noline.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 20:40:02 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/26 17:38:09 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_strcat(char *s, char *s1, char *s2)
{
	int	idx;
	int	s2_len;

	idx = 0;
	while (idx < ft_len(s1))
	{
		s[idx] = s1[idx];
		idx++;
	}
	if (s2[ft_len(s2) - 1] == '\n')
		s2_len = ft_len(s2) - 1;
	else
		s2_len = ft_len(s2);
	idx = 0;
	while (idx < s2_len)
	{
		s[ft_len(s1) + idx] = s2[idx];
		idx++;
	}
	s[ft_len(s1) + idx] = '\0';
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

	if (!ft_len(s1) && !ft_len(s2))
		return ((char *)ft_calloc(sizeof(char), 1));
	if (s2[ft_len(s2) - 1] == '\n')
		len = ft_len(s1) + ft_len(s2);
	else
		len = ft_len(s1) + ft_len(s2) + 1;
	s = (char *) malloc(sizeof(char) * len);
	if (!s)
		return (NULL);
	return (ft_strcat(s, s1, s2));
}
