# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 13:21:00 by zelhajou          #+#    #+#              #
#    Updated: 2024/04/26 15:58:14 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
INCLUDES = -I./includes -I./lib/get_next_line -I./lib/libft
SRCDIR = ./src
OBJDIR = ./obj
LIBDIR_GNL = ./lib/get_next_line
LIBDIR_LIBFT = ./lib/libft

SRCS = $(SRCDIR)/main/main.c \
       $(SRCDIR)/parsing/parse.c \
	   $(SRCDIR)/parsing/parse_color.c \
	   $(SRCDIR)/parsing/parse_texture.c \
	   $(SRCDIR)/parsing/utils/parse_utils.c \
	   $(SRCDIR)/parsing/utils/color_utils.c \
	   $(SRCDIR)/parsing/utils/config_file_utils.c \
       $(SRCDIR)/rendering/render.c \
       $(SRCDIR)/textures/texture.c \
       $(SRCDIR)/player/player.c \
       $(SRCDIR)/utils/utils.c \
	   $(LIBDIR_GNL)/get_next_line.c \
	   $(LIBDIR_GNL)/get_next_line_utils.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) libft
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBDIR_LIBFT) -lft -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	@make -C $(LIBDIR_LIBFT)

clean:
	rm -rf $(OBJDIR)
	@make -C $(LIBDIR_LIBFT) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBDIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft
