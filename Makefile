# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jangonza <jangonza@student.42urduliz.com>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/20 00:00:00 by jangonza          #+#    #+#              #
#    Updated: 2026/06/20 00:00:00 by jangonza         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

# Source files
SRCS			= src/main/main.c \
				src/main/init.c \
				src/main/dispatcher.c \
				src/main/cleanup.c \
				src/main/small_sort.c \
				src/operations/operations.c \
				src/parsing/parser.c \
				src/parsing/comprobations.c \
				src/utils/libft_utils.c \
				src/sorting/strategies.c \
				src/sorting/complex_sort.c \
				src/benchmark/benchmark.c \
				src/operations/operations_s_p.c \
				src/operations/reverse_operations.c \
				src/operations/other_operations.c

# Object files
OBJS			= $(SRCS:.c=.o)

# Header files
HEADERS			= include/push_swap.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -Iinclude -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -Iinclude -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
