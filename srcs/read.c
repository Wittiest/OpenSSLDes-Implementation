/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 01:28:32 by dpearson          #+#    #+#             */
/*   Updated: 2017/12/09 01:28:32 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

char		*reader(int fd)
{
	int		r;
	int		count;
	char	*buf;

	count = 0;
	if (!(buf = ft_memalloc((BUF_SIZE + 1) * sizeof(char))))
		exit(2);
	while ((r = read(fd, &buf[count], BUF_SIZE)) > 0)
	{
		count += r;
		if (r == BUF_SIZE)
			buf = (char *)ft_realloc(buf, (count + BUF_SIZE + 1));
	}
	if (r < 0)
		exit(4);
	if (fd)
		close(fd);
	return (buf);
}