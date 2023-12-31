/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:11:11 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/26 17:45:34 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_noline(char *line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	if (line[len - 1] == '\n')
		len--;
	return (len);
}

int	ft_len(char	*line)
{
	int	len;

	len = 0;
	while (line[len])
		len++;
	return (len);
}
