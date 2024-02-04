# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkuruthl <fkuruthl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/31 10:49:32 by fkuruthl          #+#    #+#              #
#    Updated: 2024/01/31 11:47:03 by fkuruthl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

serverSRC = server.c utils.c
clientSRC =	client.c utils.c

DEL 	= rm -rf
CC 		= cc
CFLAGS	= -Wall -Wextra -Werror

ServerOBJ = $(serverSRC:.c=.o)
ClientOBJ = $(clientSRC:.c=.o)

all : server client

server : $(ServerOBJ)
		 $(CC) $(CFLAGS) $(serverSRC) -o server


client : $(ClientOBJ)
		 $(CC) $(CFLAGS) $(clientSRC) -o client

clean :
		 $(DEL) $(ServerOBJ) $(ClientOBJ)

fclean : clean
		 $(DEL) server client

re : 	fclean  all

.PHONY: all clean fclean re