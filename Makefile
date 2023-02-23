# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ubegona <ubegona@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/30 08:54:44 by ubegona           #+#    #+#              #
#    Updated: 2023/02/23 09:35:35 by ubegona          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

OBJS = $(SRCS:.c=.o)
SRCS =  main.c libft.c fill_up.c errors.c time.c print_philo.c free_all.c checking_all.c
CC = gcc -pthread -g
NAME = philo
CFLAGS = -Wall -Wextra -Werror
 
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@
#$< gure leheneng dependentziaren izena da, kasu honetan %.c

clean: 
	rm -f *.o
fclean: clean 
	rm -f $(NAME)
re : fclean all

.PHONY: all clean fclean re
