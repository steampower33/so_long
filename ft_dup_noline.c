/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_noline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 11:50:26 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/24 15:38:16 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_dup_noline(const char *s1)
{
	size_t	src_len;
	size_t	dest_len;
	char	*dest;

	src_len = 0;
	while (s1[src_len])
		src_len++;
	if (s1[src_len - 1] == '\n')
		src_len--;
	dest = (char *)malloc((sizeof(char) * (src_len + 1)));
	if (dest == NULL)
		return (NULL);
	dest_len = 0;
	while (dest_len < src_len)
	{
		dest[dest_len] = s1[dest_len];
		dest_len++;
	}
	dest[dest_len] = '\0';
	return (dest);
}
