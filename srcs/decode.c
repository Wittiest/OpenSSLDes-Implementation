/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 14:10:00 by dpearson          #+#    #+#             */
/*   Updated: 2017/12/06 14:10:00 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"
#include <stdio.h>




/*
**	Issue: What about the extra == signs??
*/
static char		rev(char **plain_out, char *cipher_in, char frag_e, uint8_t *turn)
{
	if (*turn == 0)
	{
		**plain_out = (*cipher_in << 2);
		(*plain_out)[1] = (*(++cipher_in) >> 4);
		
		// get first 2 of next which will be at index 5,4 and move to 1,0
		(*turn) = 1;
		(*plain_out)++;
		return() // return next character shifted left
	}
}

/*
**	Converting from sets of 6 bits to 8 bits
*/

char	*base64_decode(const char *cipher_in)
{
	char	*plain_out;
	char	*plain_begin;
	char	frag_e;
	int		turn;

	plain_out = ft_strnew(ft_strlen(cipher_in));
	plain_begin = plain_out;
	while (*cipher_in)
		frag_e = rev(&plain_out, cipher_in, frag_e, &turn);
	printf("%s\n", cipher_in);
	return ((char *)cipher_in);
}
