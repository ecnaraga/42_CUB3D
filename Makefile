# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: galambey <galambey@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/02 11:40:51 by galambey          #+#    #+#              #
#    Updated: 2024/05/14 11:18:48 by galambey         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 			= 	cub3D
NAME_BONUS 			= 	cub3D_bonus
CC 				= 	cc
C_FLAGS 		= 	-Wall -Wextra -Werror -g3 -MMD
LIB_FLAG 		= 	-lreadline
INC_LIBFT 		= 	./libft/megalibft.a
INC_MLX			=	-L./minilibx -lmlx -lX11 -lXext
INC_OTHERLIB	=	-lm

################################### SOURCES ###################################

MAIN_DIR		=	main/
MAIN_SRCS		=	main.c

PARSING_DIR		=	parsing/
PARSING_SRCS	=	map_textures.c \
					map_textures_utils.c \
					parsing_utils.c \
					ft_split_mcgic.c \
					get_map.c \
					get_map_utils.c \
					check_borders.c \
					get_map_x_borders.c \
					get_map_y_borders.c 

BONUS_DIR		=	bonus/
BONUS_SRCS		=	minimap_utils.c \
					doors.c \
					handle_mouse.c \
					sprite.c \
					map_colors.c \
					sprite_bis.c \
					draw.c \
					bresenham_diag.c

WINDOW_DIR		=	window/
WINDOW_SRCS		=	open_window.c \
					close_window.c \
					event.c \
					move.c \
					rotation.c
					
RAYCASTING_DIR	=	raycasting/
RAYCASTING_SRCS	=	calculation_utils.c \
					raycasting.c \
					raycasting_utils.c \
					hit_horizontal_wall.c \
					hit_vertical_wall.c
					
DRAW_DIR		=	draw/
DRAW_SRCS		=	bresenham_vh.c \
					put_to_img.c 
					

MAGIC_MLC_DIR	= 	magic_malloc/
MAGIC_MLC_SRCS	= 	ft_magic_malloc.c \
	   				ft_magic_malloc_utils.c

############################# HANDLE DIRECTORIES ##############################

SRCS_DIR 		= 	mandatory/srcs/
SRCS_BONUS_DIR 	= 	bonus/srcs/

SRCS			=	$(addprefix $(MAIN_DIR), $(MAIN_SRCS)) \
				$(addprefix $(PARSING_DIR), $(PARSING_SRCS)) \
				$(addprefix $(WINDOW_DIR), $(WINDOW_SRCS)) \
				$(addprefix $(RAYCASTING_DIR), $(RAYCASTING_SRCS)) \
				$(addprefix $(DRAW_DIR), $(DRAW_SRCS)) \
				$(addprefix $(ERROR_DIR), $(ERROR_SRCS)) \
				$(addprefix $(MAGIC_MLC_DIR), $(MAGIC_MLC_SRCS))
					
SRCS_BONUS		=	$(addprefix $(MAIN_DIR), $(MAIN_SRCS)) \
				$(addprefix $(PARSING_DIR), $(PARSING_SRCS)) \
				$(addprefix $(WINDOW_DIR), $(WINDOW_SRCS)) \
				$(addprefix $(RAYCASTING_DIR), $(RAYCASTING_SRCS)) \
				$(addprefix $(DRAW_DIR), $(DRAW_SRCS)) \
				$(addprefix $(BONUS_DIR), $(BONUS_SRCS)) \
				$(addprefix $(MAGIC_MLC_DIR), $(MAGIC_MLC_SRCS))

OBJS_DIR 		= 	.objs/
OBJS_BONUS_DIR 	= 	.objs_bonus/

OBJS_NAMES 			= 	$(SRCS:.c=.o)
OBJS_NAMES_BONUS	= 	$(SRCS_BONUS:.c=.o)

OBJS			= $(addprefix $(OBJS_DIR), $(OBJS_NAMES))
OBJS_BONUS		= $(addprefix $(OBJS_BONUS_DIR), $(OBJS_NAMES_BONUS))

DEPS 		:= $(OBJS:.o=.d)
DEPS_BONUS 	:= $(OBJS_BONUS:.o=.d)

#################################### RULES ####################################

all : $(NAME)

$(NAME) : $(OBJS)
	make -j -C ./libft
	make -j -C ./minilibx
	$(CC) $(C_FLAGS) $(OBJS) $(INC_LIBFT) $(INC_MLX) $(INC_OTHERLIB) $(LIB_FLAG) -o $@

$(OBJS_DIR)%.o:$(SRCS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(C_FLAGS) -c $< -o $@ $(MLX_FLAGS)

bonus : $(NAME_BONUS)
 
$(NAME_BONUS) :$(OBJS_BONUS)
	make -j -C ./libft
	make -j -C ./minilibx
	$(CC) $(C_FLAGS) $(OBJS_BONUS) $(INC_LIBFT) $(INC_MLX) $(INC_OTHERLIB) $(LIB_FLAG) -o $@

$(OBJS_BONUS_DIR)%.o:$(SRCS_BONUS_DIR)%.c
	mkdir -p $(@D)
	$(CC) $(C_FLAGS) -c $< -o $@ $(MLX_FLAGS)

-include $(DEPS)

clean :
	make -j clean -C ./libft
	rm -rf $(OBJS_DIR)
	rm -rf $(OBJS_BONUS_DIR)

fclean : clean
	make -j fclean -C ./libft
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re : fclean
	make all

.PHONY : all bonus clean fclean re
