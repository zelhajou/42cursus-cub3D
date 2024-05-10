# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: zelhajou <zelhajou@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/20 13:21:00 by zelhajou          #+#    #+#              #
#    Updated: 2024/05/10 11:33:58 by zelhajou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = cc
CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address
SRCDIR = ./src
OBJDIR = ./obj
LIBDIR_GNL = ./lib/get_next_line
LIBDIR_LIBFT = ./lib/libft
LIBMLX = ./lib/MLX42
INCLUDES = -I./includes -I./lib/get_next_line -I./lib/libft -I./lib/MLX42/include
MLX42_FLAGS = -framework Cocoa -framework IOKit $(LIBMLX)/build/libmlx42.a -Iinclude -lglfw -L $(shell brew --prefix glfw)/lib

SRCS = $(SRCDIR)/main.c \
	   $(SRCDIR)/parsing/config/config_parsing.c \
	   $(SRCDIR)/parsing/config/config_validation.c \
	   $(SRCDIR)/parsing/texture/texture_parsing.c \
	   $(SRCDIR)/parsing/texture/texture_validation.c \
       $(SRCDIR)/parsing/color/color_parsing.c \
	   $(SRCDIR)/parsing/color/color_validation.c \
	   $(SRCDIR)/parsing/map/map_parsing.c \
	   $(SRCDIR)/parsing/map/map_validation.c \
	   $(SRCDIR)/parsing/map/map_validation2.c \
	   $(SRCDIR)/rendering/drawing.c \
	   $(SRCDIR)/rendering/hooks.c \
	   $(SRCDIR)/rendering/movement.c \
	   $(SRCDIR)/rendering/raycasting_engine.c \
	   $(SRCDIR)/rendering/raycasting_init.c \
	   $(SRCDIR)/rendering/rendering.c \
	   $(SRCDIR)/utils/config_utils.c \
	   $(SRCDIR)/utils/error_utils.c \
	   $(SRCDIR)/utils/rendering_utils.c \
	   $(SRCDIR)/utils/rendering_utils2.c \
	   $(LIBDIR_GNL)/get_next_line.c \
	   $(LIBDIR_GNL)/get_next_line_utils.c \

OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: libmlx $(NAME)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

$(NAME): $(OBJS) libft ./includes/cub3d.h ./includes/engine.h
	$(CC) $(MLX42_FLAGS) $(CFLAGS) $(OBJS) -L$(LIBDIR_LIBFT) -lft -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c ./includes/cub3d.h ./includes/engine.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

libft:
	@make -C $(LIBDIR_LIBFT)

clean:
	rm -rf $(OBJDIR)
	@make -C $(LIBDIR_LIBFT) clean
	rm -rf $(LIBMLX)/build

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBDIR_LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re libft
