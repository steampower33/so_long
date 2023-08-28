/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_util.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 20:41:30 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/28 12:26:04 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen_p(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	ft_putchar(char c, int *result)
{
	if (write(1, &c, 1) == -1)
		*result = -1;
	else
		*result += 1;
}

void	ft_putstr(char *c, int *result)
{
	size_t	idx;

	if (c == (char *) NULL)
		c = "(null)";
	idx = 0;
	while (idx < ft_strlen_p(c))
	{
		ft_putchar(c[idx++], result);
		if (*result == -1)
			return ;
	}
}
