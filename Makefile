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
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
RM				= rm -f

# Source files
SRCS			= main.c \
				init.c \
				dispatcher.c \
				cleanup.c \
				small_sort.c \
				small_sort_utils.c\
				operations.c \
				parser.c \
				comprobations.c \
				libft_utils.c \
				string_utils.c \
				strategies.c \
				strategy_utils.c \
				rotation_utils.c \
				simple_strategy.c \
				medium_strategy.c \
				complex_sort.c \
				benchmark.c \
				benchmark_operations.c \
				operations_s_p.c \
				reverse_operations.c \
				other_operations.c

# Object files
OBJS			= $(SRCS:.c=.o)

# Header files
HEADERS			= push_swap.h

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -I. -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
