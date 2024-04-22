# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 13:21:00 by zelhajou          #+#    #+#              #
#    Updated: 2024/04/22 15:19:02 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I./includes -I./lib/get_next_line
SRCDIR = ./src
OBJDIR = ./obj
LIBDIR = ./lib/get_next_line

SRCS = $(SRCDIR)/main/main.c \
       $(SRCDIR)/parsing/parse.c \
       $(SRCDIR)/rendering/render.c \
       $(SRCDIR)/textures/texture.c \
       $(SRCDIR)/player/player.c \
       $(SRCDIR)/utils/utils.c \
       $(LIBDIR)/get_next_line.c \
       $(LIBDIR)/get_next_line_utils.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJDIR)/%.o: $(LIBDIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

