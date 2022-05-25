# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yjimpei <yjimpei@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/14 14:04:18 by yjimpei           #+#    #+#              #
#    Updated: 2021/05/28 02:06:28 by yjimpei          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT_OBJ_FILES =	libft/ft_memset.o libft/ft_putchar_fd.o libft/ft_strncmp.o libft/ft_substr.o libft/ft_memchr.o libft/ft_isalpha.o libft/ft_strrchr.o libft/ft_toupper.o libft/ft_split.o libft/ft_memmove.o libft/ft_strmapi.o libft/ft_strtrim.o libft/ft_strdup.o libft/ft_calloc.o libft/ft_strlcat.o libft/ft_tolower.o libft/ft_atoi.o libft/ft_isalnum.o libft/ft_itoa.o libft/ft_putstr_fd.o libft/ft_isdigit.o libft/ft_strnstr.o 
LIBFT_OBJ_FILES +=	libft/ft_memcmp.o libft/ft_strlcpy.o libft/ft_strlen.o 
LIBFT_OBJ_FILES +=	libft/ft_strjoin.o libft/ft_isascii.o libft/ft_memcpy.o libft/ft_strchr.o libft/ft_bzero.o
LIBFT_OBJ_FILES +=	libft/ft_putnbr_fd.o libft/ft_putendl_fd.o libft/ft_isprint.o 
LIBFT_OBJ_FILES +=	libft/ft_memccpy.o libft/ft_lstadd_front.o libft/ft_lstdelone.o libft/ft_lstadd_back.o libft/ft_lstlast.o
LIBFT_OBJ_FILES +=	libft/ft_lstnew.o libft/ft_lstclear.o libft/ft_lstiter.o libft/ft_lstmap.o libft/ft_lstsize.o
FT_PRINTF_OBJ_FILES =	srcs/ft_printf.o srcs/ft_utoa.o srcs/ft_utoh.o srcs/ft_utof2.o srcs/put_valious.o
FT_PRINTF_OBJ_FILES +=	srcs/ft_put_c.o srcs/ft_put_d.o srcs/ft_put_s.o srcs/ft_put_x.o srcs/ft_put_p.o srcs/ft_put_u.o srcs/ft_info.o
FT_PRINTF_OBJ_FILES +=	srcs/ft_info2.o srcs/ft_put_d2.o srcs/ft_put_x2.o
HEADER_FILES = include
CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(LIBFT_OBJ_FILES) ${FT_PRINTF_OBJ_FILES}
	ar rcs ${NAME} ${LIBFT_OBJ_FILES} ${FT_PRINTF_OBJ_FILES}

%.o: %.c $(HEADER_FILES)
	$(CC) -c $(CFLAGS) -o $@ $< -I ${HEADER_FILES}

clean:
	rm -f $(LIBFT_OBJ_FILES) $(FT_PRINTF_OBJ_FILES)

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

.PHONY: all clean fclean re test t_clean
