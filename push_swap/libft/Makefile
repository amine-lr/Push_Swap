# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: molariou <molariou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/04/25 14:22:48 by molariou          #+#    #+#              #
#    Updated: 2026/05/10 18:30:00 by molariou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

INCLUDES = -Iinclude

SRC_DIR = src
PRINTF_DIR = ft_printf
OBJ_DIR = obj

SRC_FILES = \
	ft_atoi.c ft_lstdelone.c ft_putendl_fd.c ft_strncmp.c ft_bzero.c \
	ft_lstiter.c ft_putnbr_fd.c ft_strnstr.c ft_calloc.c ft_lstlast.c \
	ft_putstr_fd.c ft_strrchr.c ft_isalnum.c ft_lstmap.c ft_split.c \
	ft_strtrim.c ft_isalpha.c ft_lstnew.c ft_strchr.c ft_substr.c ft_isascii.c \
	ft_lstsize.c ft_strdup.c ft_tolower.c ft_isdigit.c ft_memchr.c ft_striteri.c \
	ft_toupper.c ft_isprint.c ft_memcmp.c ft_strjoin.c ft_itoa.c ft_memcpy.c \
	ft_strlcat.c ft_lstadd_back.c ft_memmove.c ft_strlcpy.c ft_lstadd_front.c \
	ft_memset.c ft_strlen.c ft_lstclear.c ft_putchar_fd.c ft_strmapi.c

PRINTF_FILES = \
	ft_printf.c printing.c puthexnbr.c

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES)) \
       $(addprefix $(PRINTF_DIR)/, $(PRINTF_FILES))

OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re