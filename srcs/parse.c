/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 13:57:22 by dpearson          #+#    #+#             */
/*   Updated: 2017/12/07 13:57:23 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

void	init_flags(t_flags *flags)
{
	flags->base64 = 0;
	flags->des = 0;
	flags->des_ecb = 0;
	flags->des_cbc = 0;
	flags->decrypt = 0;
	flags->k = 0;
	flags->i_fd = 0;
	flags->o_fd = 1;
	flags->read_text = NULL;
}

void	parse_type(char *str, t_flags *flags)
{
	if (ft_strequ(str, "base64"))
		flags->base64 = 1;
	else if (ft_strequ(str, "des"))
		flags->des = 1;
	else if (ft_strequ(str, "des-ecb"))
		flags->des_ecb = 1;
	else if (ft_strequ(str, "des-cbc"))
		flags->des_cbc = 1;
	else
		print_error();
}

void	parse_flags(int argc, char **argv, t_flags *flags, int i)
{
	while (i < argc)
	{
		if (ft_strequ(argv[i], "-d"))
			flags->decrypt = 1;
		else if (ft_strequ(argv[i], "-a"))
			flags->base64 = 1;
		else if (ft_strequ(argv[i], "-i"))
		{
			if ((i + 1) >= argc)
				print_error();
			flags->i_fd = open(argv[i + 1], O_RDONLY);
		}
		else if (ft_strequ(argv[i], "-o"))
		{
			if ((i + 1) < argc)
				print_error();
			flags->o_fd = open(argv[i + 1], O_RDONLY);
		}
		else if (!(ft_strequ(argv[i], "-e")))
			print_error();
		i++;
	}
}
