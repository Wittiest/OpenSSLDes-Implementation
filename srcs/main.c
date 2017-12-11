/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 23:21:53 by dpearson          #+#    #+#             */
/*   Updated: 2017/12/02 23:21:54 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	t_flags	flags;

	if (argc < 2)
		print_error();
	init_flags(&flags);
	parse_type(argv[1], &flags);
	parse_flags(argc, argv, &flags, 2);
	flags.read_text = reader(flags.i_fd);
	if (flags.base64)
		print_64(base64_encode(flags.read_text), flags.o_fd);
	return (1);
}