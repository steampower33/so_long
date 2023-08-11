/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seunlee2 <seunlee2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 17:28:58 by seunlee2          #+#    #+#             */
/*   Updated: 2023/08/11 19:44:09 by seunlee2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str, int code)
{
	perror(str);
	exit(code);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
		ft_error("Error\n", 1);
	// if (ft_strnstr())
	printf("%s\n", argv[1] + ft_strlen(argv[1]) - 4);
}
