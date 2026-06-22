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
SRCS			= push_swap.c \
				operations.c \
				parser.c \
				comprobations.c \
				libft_utils.c \
				simple_sort.c \
				medium_sort.c \
				complex_sort.c \
				adaptive_sort.c \
				benchmark.c \
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
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
