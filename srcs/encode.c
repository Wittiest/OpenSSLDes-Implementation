/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 15:18:04 by dpearson          #+#    #+#             */
/*   Updated: 2017/12/03 15:18:18 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ssl.h"

static char 	base64_val(char val)
{
	static const char	*encoding = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmno"
									"pqrstuvwxyz0123456789+/";
	if (val > 63)
		return ('=');
	return encoding[(uint8_t)val];
}

static char		rot(char **cipher_out, char frag_s, char frag_e, uint8_t *turn)
{
	if (*turn == 0)
	{
		**cipher_out = base64_val((frag_s >> 2));
		(*turn) = 1;
		(*cipher_out)++;
		return ((frag_s & 3) << 4);
	}
	else if (*turn == 1)
	{
		**cipher_out = base64_val((frag_s >> 4) + frag_e);
		(*turn) = 2;
		(*cipher_out)++;	
		return ((frag_s & 15) << 2);
	}
	else
	{
		**cipher_out = base64_val((frag_s >> 6) + frag_e);
		(*cipher_out)[1] = base64_val(frag_s & 63);
		(*turn) = 0;
		(*cipher_out) += 2;	
		return (0);
	}
}

/*
**	Base64 encodes each set of three bytes into four bytes.
**	The output is padded to always be a multiple of four.
**	The base-64 rep of string size n is ceil(n / 3) * 4
**	We can use integer math to avoid float casts.
*/

char			*base64_encode(const char *plain_in)
{
	char	*cipher_out;
	char	*cipher_begin;
	char	frag_e;
	uint8_t	turn;

	turn = 0;
	cipher_out = ft_strnew(4 * ((ft_strlen(plain_in) + 2) / 3));
	cipher_begin = cipher_out;
	while (*plain_in)
		frag_e = rot(&cipher_out, *plain_in++, frag_e, &turn);
	if (turn)
	{
		*cipher_out = base64_val(frag_e);
		cipher_out++;
		turn++;
	}
	if (turn)
		while (turn++ < 4)
			*(cipher_out++) = '=';
	return cipher_begin;
}
