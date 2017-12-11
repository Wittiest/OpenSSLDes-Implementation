#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpearson <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/02 23:18:12 by dpearson          #+#    #+#              #
#    Updated: 2017/12/02 23:18:13 by dpearson         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC				=	gcc

NAME			=	ft_ssl

LIBS			=	./libs

LIBFT_DIR		=	$(LIBS)/libft

INCLUDES_DIR	=	./includes

CFLAGS			+=	-Wall -Wextra -Werror
CFLAGS			+=	-I $(INCLUDES_DIR)

FILENAMES		=	encode.c main.c decode.c parse.c error.c read.c print.c

SRC 			=	$(addprefix srcs/, $(FILENAMES))

OBJ				=	$(SRC:.c=.o)

LIBFT			=	$(LIBFT_DIR)/libft.a


all: $(NAME)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
clean:
		rm -f $(OBJ)
		make -C $(LIBFT_DIR) clean
fclean: clean
		rm -rf $(NAME)
		make -C $(LIBFT_DIR) fclean
re: fclean all
