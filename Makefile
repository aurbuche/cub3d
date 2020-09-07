# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <user42@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 17:51:18 by user42            #+#    #+#              #
#    Updated: 2020/09/07 17:08:04 by user42           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

BLUE =\033[0;38;5;123m
LIGHT_PINK = \033[0;38;5;200m
PINK = \033[0;38;5;198m
DARK_BLUE = \033[1;38;5;110m
GREEN = \033[1;32;111m
LIGHT_GREEN = \033[0;38;5;121m
LIGHT_RED = \033[0;31;5;110m
FLASH_GREEN = \033[33;32m
WHITE_BOLD = \033[37m
GREY = \033[3;90m
ORANGE = \033[3;91m
YELLOW = \033[0;33m

SRCS_PARSING	= 	$(addprefix parsing/, ft_check.c ft_map_analyze.c\
							ft_disp_map_ok.c ft_check_inside.c\
							ft_disp_error.c ft_init_cub.c ft_parse.c\
							ft_print_params.c)

SRCS_CONVERT	=	$(addprefix convert/, f_converter.c c_converter.c\
							no_converter.c so_converter.c we_converter.c\
							ea_converter.c s_converter.c r_converter.c)

SRCS_DISPLAY	=	$(addprefix display/, ft_begin_disp.c ft_close.c\
							ft_loop.c ft_move.c ft_draw.c ft_textures.c\
							ft_colors.c ft_start_windows.c ft_player.c\
							ft_raycasting.c ft_data.c ft_turn.c)

SRCS_NAME		=	cub3d.c $(SRCS_PARSING) $(SRCS_CONVERT) $(SRCS_DISPLAY)

SRC_PATH		=	srcs/

SRCS			=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

LIBFT_PATH		=	./libft
MINILIBX_PATH	=	./minilibx
HEADERS			=	includes/libcub3d.h
OBJ				=	$(SRCS:.c=.o) libft/libft.a minilibx/libmlx.a
OBJ_PATH		=	obj/
NAME			=	Cub3D
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror -g3 #-fsanitize=address
MLXFLAGS		=	-lX11 -lXext -L minilibx/ -lmlx -lm -pthread -lbsd
RM				=	rm -f

all :	libft_all minilibx_all ${NAME}
		@

$(NAME) :			$(OBJ)
						@$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLXFLAGS)
						printf "\033[2K\r$(DARK_BLUE)Cub3D\t:\t$(LIGHT_GREEN)Updated\n\033[0m"

%.o :				%.c $(HEADERS)
						@$(CC) $(CFLAGS) -o $@ -c $<
						@printf "	\033[2K\r$(LIGHT_RED)Compiling...		\033[0m"

clean :				libft_clean #minilibx_clean
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/		\033[37m"
						@sleep 0.1
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/.		\033[37m"
						@sleep 0.1
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/..		\033[37m"
						@sleep 0.1
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/...	\033[37m"
						@sleep 0.1
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/		\033[37m"
						@sleep 0.1
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/.		\033[37m"
						@sleep 0.1
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/..		\033[37m"
						@sleep 0.1
						@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/...	\033[37m"
						@sleep 0.1
						@$(RM) -f $(OBJ)
						@printf "\33[2K\r$(LIGHT_RED)Deleted successfully!\n\033[0m"

fclean 	:			clean
						@$(RM) ${NAME}

re :				fclean all


libft_all :
					@make -C $(LIBFT_PATH) all


libft_clean :
					@make -C $(LIBFT_PATH) clean


libft_fclean :
					@make -C $(LIBFT_PATH) fclean


minilibx_all :
					@make -C $(MINILIBX_PATH) all


minilibx_clean :
					@make -C $(MINILIBX_PATH) clean

.PHONY :		all clean fclean re