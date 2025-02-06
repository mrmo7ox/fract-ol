# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: moel-oua <moel-oua@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/06 22:20:33 by moel-oua          #+#    #+#              #
#    Updated: 2025/02/06 22:20:37 by moel-oua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = main.c utils.c mlx_utils.c fracles.c

OBJECTS = $(SRCS:.c=.o)
NAME = fract-ol

all: $(NAME)
	
$(NAME):$(OBJECTS)
	$(CC)  $(CFLAGS) $(OBJECTS) -lmlx -lX11 -lXext -o $@

 %.o: %.c ./fract_ol.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	clean 
