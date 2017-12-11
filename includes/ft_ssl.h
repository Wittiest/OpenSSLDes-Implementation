/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ssl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpearson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 23:22:36 by dpearson          #+#    #+#             */
/*   Updated: 2017/12/02 23:34:52 by dpearson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SSL_H
#define FT_SSL_H

#include <fcntl.h>
#include <unistd.h>
#include <sys/uio.h>
#include <sys/types.h>
#include <pwd.h> // For getpass
#include <readpassphrase.h> // For readpassphrase
#include <curses.h> // for getch
#include <stdlib.h>
#include "../libs/libft/includes/libft.h"

#define BUF_SIZE 64

typedef struct	s_flags
{
	uint8_t		base64; // for base64 or -a flag
	uint8_t		des;
	uint8_t		des_ecb;
	uint8_t		des_cbc;
	uint8_t		decrypt; // if null, encrypt
	uint8_t		k; // key in hex is next arg
	int			i_fd;
	int			o_fd;
	char		*read_text;
}				t_flags;

char	*base64_encode(const char *plain_in);
char	*base64_decode(const char *cipher_in);
void	print_error(void);
void	parse_type(char *str, t_flags *flags);
void	parse_flags(int argc, char **argv, t_flags *flags, int i);
char	*reader(int fd);
void	print_64(char *str, int fd);
void	init_flags(t_flags *flags);
#endif
