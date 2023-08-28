/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 17:23:28 by seunlee2          #+#    #+#             */
/*   Updated: 2023/05/15 22:03:20 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_conversions(const char *str, va_list ap, int *result, size_t *idx)
{
	if (str[*idx] != '%')
		ft_putchar(str[*idx], result);
	else if (str[*idx] == '%' && str[*idx + 1])
	{
		if (str[*idx + 1] == 'c')
			ft_putchar(va_arg(ap, int), result);
		else if (str[*idx + 1] == 's')
			ft_putstr(va_arg(ap, char *), result);
		else if (str[*idx + 1] == 'p')
			ft_putnbr_hex(va_arg(ap, unsigned long long), result,
				str[*idx + 1]);
		else if (str[*idx + 1] == 'd')
			ft_putnbr_int(va_arg(ap, int), result);
		else if (str[*idx + 1] == 'i')
			ft_putnbr_int(va_arg(ap, int), result);
		else if (str[*idx + 1] == 'u')
			ft_putnbr_uint(va_arg(ap, unsigned int), result);
		else if ((str[*idx + 1] == 'x' || str[*idx + 1] == 'X'))
			ft_putnbr_hex(va_arg(ap, unsigned int), result, str[*idx + 1]);
		else if (str[*idx + 1] == '%')
			ft_putchar('%', result);
		else
			ft_putchar(str[*idx + 1], result);
		*idx += 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	size_t	idx;
	int		result;

	if (!str)
		return (0);
	idx = 0;
	result = 0;
	va_start(ap, str);
	while (str[idx])
	{
		ft_conversions(str, ap, &result, &idx);
		if (result == -1)
			return (-1);
		idx++;
	}
	va_end(ap);
	return (result);
}
