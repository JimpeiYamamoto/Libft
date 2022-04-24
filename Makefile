# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/15 23:52:58 by yjimpei           #+#    #+#              #
#    Updated: 2022/04/24 15:28:59 by yjimpei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
REG_OBJ_FILES = ft_memset.o ft_putchar_fd.o ft_strncmp.o ft_substr.o ft_memchr.o ft_isalpha.o ft_strrchr.o ft_toupper.o ft_split.o ft_memmove.o ft_strmapi.o ft_strtrim.o ft_strdup.o ft_calloc.o ft_strlcat.o ft_tolower.o ft_atoi.o ft_isalnum.o ft_itoa.o ft_putstr_fd.o ft_isdigit.o ft_strnstr.o ft_memcmp.o ft_strlcpy.o ft_strlen.o ft_strjoin.o ft_isascii.o ft_memcpy.o ft_strchr.o ft_bzero.o ft_putnbr_fd.o ft_putendl_fd.o ft_isprint.o ft_memccpy.o ft_free.o ft_freepptr.o
BONUS_OBJ_FILES = ft_lstadd_front.o ft_lstdelone.o ft_lstadd_back.o ft_lstlast.o ft_lstnew.o ft_lstclear.o ft_lstiter.o ft_lstmap.o ft_lstsize.o
HEADER_FILES = libft.h
CC = gcc
CFLAGS = -Wall -Wextra -Werror

ifdef WITH_BONUS
OBJ_FILES = $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)
else
OBJ_FILES = $(REG_OBJ_FILES)
endif

all: $(NAME)

$(NAME): $(OBJ_FILES)
	ar rcs ${NAME} ${OBJ_FILES}

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $<

bonus:
	$(MAKE) WITH_BONUS=1 all

clean:
	rm -f $(REG_OBJ_FILES) $(BONUS_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re
