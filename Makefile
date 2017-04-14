# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvlad <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/08 14:24:38 by mvlad             #+#    #+#              #
#    Updated: 2016/12/08 14:24:44 by mvlad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC_DIR = ./src/
OBJ_DIR = ./src/
INC_DIR = ./inc/
LIB_DIR = ./libft/
LIB_INC = $(LIB_DIR)
LIB_LIB = $(LIB_DIR)libft.a

OBJ	=	fdf_center_current.o \
		fdf_center_find.o \
		fdf_center_place.o \
		fdf_center_zero.o \
		fdf_draw.o \
		fdf_error_sup.o \
		fdf_error.o \
		fdf_key_core.o \
		fdf_mlx.o \
		fdf_move.o \
		fdf_my_color.o \
		fdf_pixel_color_z.o \
		fdf_pixel_color.o \
		fdf_pixel_malloc.o \
		fdf_pixel_read.o \
		fdf_rotate_x.o \
		fdf_rotate_y.o \
		fdf_rotate_z.o \
		fdf_rotate.o \
		fdf_ui.o \
		fdf_validate.o \
		fdf_win_setup.o \
		fdf_zoom_auto_minus.o \
		fdf_zoom_auto_plus.o \
		fdf_zoom.o \
		fdf.o \
		ft_atoi_hex.o \
		ft_ishex.o \
		get_next_line.o


LIB = $(LIB_DIR)libft.a

HEADERS	= $(INC_DIR)

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
MLX		= -lmlx -framework OpenGL -framework AppKit
INC_OPT = -I $(LIB_INC) -I $(INC_DIR)
OUT_OPT = -o
OBJ_OPT = $< -o $@
LIB_OPT	= -c

RMF 	= rm -f

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(LIB_OPT) $(OBJ_OPT) $(INC_OPT)

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR), $(OBJ))
	$(MAKE) -C ./libft/
	$(CC) $(MLX) $(CFLAGS) $(LIB_LIB) $^ $(OUT_OPT) $(NAME)

clean:
	$(RMF) $(addprefix $(OBJ_DIR), $(OBJ))
	cd $(LIB_DIR) && $(MAKE) clean

fclean: clean
	$(RMF) $(NAME)
	cd $(LIB_DIR) && $(MAKE) fclean

re: fclean all
	cd $(LIB_DIR) && $(MAKE) re
