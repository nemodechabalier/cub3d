# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nde-chab <nde-chab@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/27 10:27:53 by nde-chab          #+#    #+#              #
#    Updated: 2024/09/18 16:41:03 by nde-chab         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft_printf_gnl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
INCLUDES = -I .

# Source directories
SRC_DIR_LIBFT = libtf/
SRC_DIR_FT_PRINTF = ft_printf/
SRC_DIR_GNL = get_next_line/

# Source files
FUNC_LIBFT = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
             ft_isascii.c ft_isdigit.c ft_isprint.c ft_memchr.c \
             ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c \
             ft_strdup.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strncmp.c \
             ft_strnstr.c ft_strrchr.c ft_tolower.c ft_toupper.c \
             ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
             ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
             ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

FUNC_FT_PRINTF = ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c \
                 ft_print_base.c ft_putunbr.c 

FUNC_GNL = get_next_line.c get_next_line_utils.c

SRCS_LIBFT = $(addprefix $(SRC_DIR_LIBFT), $(FUNC_LIBFT))
SRCS_FT_PRINTF = $(addprefix $(SRC_DIR_FT_PRINTF), $(FUNC_FT_PRINTF))
SRCS_GNL = $(addprefix $(SRC_DIR_GNL), $(FUNC_GNL))

SRCS = $(SRCS_LIBFT) $(SRCS_FT_PRINTF) $(SRCS_GNL)
SRCSALL = $(SRCS)

OBJS_DIR = obj/
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
OBJSALL = $(addprefix $(OBJS_DIR), $(notdir $(SRCSALL:.c=.o)))

# Rule to compile .c files to .o files
$(OBJS_DIR)%.o: $(SRC_DIR_LIBFT)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o: $(SRC_DIR_FT_PRINTF)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJS_DIR)%.o: $(SRC_DIR_GNL)%.c
	@mkdir -p $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Rule to create the library
$(NAME): $(OBJS)
	ar -rcs $(NAME) $(OBJS)

# Clean object files
clean:
	rm -rf $(OBJS_DIR)

# Full clean
fclean: clean
	rm -f $(NAME)

# Recompile everything
re: fclean all

# Default target
all: $(NAME)

.PHONY: all clean fclean re
