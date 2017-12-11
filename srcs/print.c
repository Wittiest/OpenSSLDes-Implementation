/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 02:51:48 by dpearson          #+#    #+#             */
/*   Updated: 2017/12/09 02:51:49 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

/*
**	Printing 64 characters at a time to match openssl base64
*/
void	print_64(char *str, int fd)
{
	int		len;

	while (*str)
	{
		len = ft_strlen(str);
		str += write(fd, str, (len >= 64) ? 64 : len);
		write(fd, "\n", 1);
	}
}