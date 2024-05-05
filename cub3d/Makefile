# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 13:21:00 by zelhajou          #+#    #+#              #
#    Updated: 2024/05/05 08:40:02 by beddinao         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = #-g -fsanitize=address#-Wall -Wextra -Werror #-g -fsanitize=address
INCLUDES = -I./includes -I./lib/get_next_line -I./lib/libft -I./lib/MLX42
SRCDIR = ./src
OBJDIR = ./obj
LIBDIR_GNL = ./lib/get_next_line
LIBDIR_LIBFT = ./lib/libft
MLX42_FLAGS = -framework Cocoa -framework IOKit ./lib/MLX42/build/libmlx42.a -Iinclude -lglfw -L $(shell brew --prefix glfw)/lib

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/parsing/config_file/config_file_parsing.c \
	   $(SRCDIR)/parsing/config_file/config_file_parsing_utils.c \
	   $(SRCDIR)/parsing/config_file/config_file_validation.c \
	   $(SRCDIR)/parsing/config_file/config_line_handlers.c \
	   $(SRCDIR)/parsing/texture/texture_parsing.c \
	   $(SRCDIR)/parsing/texture/texture_parsing_utils.c \
	   $(SRCDIR)/parsing/texture/texture_validation.c \
       $(SRCDIR)/parsing/color/color_parsing.c \
	   $(SRCDIR)/parsing/color/color_parsing_utils.c \
	   $(SRCDIR)/parsing/color/color_validation.c \
	   $(LIBDIR_GNL)/get_next_line.c \
	   $(LIBDIR_GNL)/get_next_line_utils.c \
	$(SRCDIR)/utils/general_utils.c \
	$(SRCDIR)/utils/rayCaster_utils.c \
	$(SRCDIR)/utils/rayCaster_utils_2.c \
	$(SRCDIR)/rendering/hooks.c \
	$(SRCDIR)/rendering/movements.c \
	$(SRCDIR)/rendering/rayCaster.c \
	$(SRCDIR)/rendering/rayCaster_init.c \
	$(SRCDIR)/rendering/rayCaster_engine.c

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS) libft ./includes/cub3d.h ./includes/engine.h
	$(CC) $(MLX42_FLAGS) $(CFLAGS) $(OBJS) -L$(LIBDIR_LIBFT) -lft -o $(NAME)

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
