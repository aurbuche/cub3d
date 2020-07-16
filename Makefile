# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurelienbucher <aurelienbucher@student.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/02 14:12:32 by tclaudel          #+#    #+#              #
#    Updated: 2020/07/15 09:21:38 by aurelienbuc      ###   ########lyon.fr    #
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
							ft_disp_error.c ft_init_cub.c ft_parse.c)

SRCS_CONVERT	=	$(addprefix convert/, f_converter.c c_converter.c\
							no_converter.c so_converter.c we_converter.c\
							ea_converter.c s_converter.c r_converter.c)

SRCS_DISPLAY	=	$(addprefix display/, ft_begin_disp.c)

SRCS_NAME		=	cub3d.c $(SRCS_PARSING) $(SRCS_CONVERT) $(SRCS_DISPLAY)

SRC_PATH		=	srcs/

SRCS			=	$(addprefix $(SRC_PATH), $(SRCS_NAME))

# HEADER			=	includes/

# OBJ_NAME		=	$(addprefix $(OBJ_PATH), ${SRCS_NAME:.c=.o}) libft/libft.a minilibx/libmlx.a

# OBJ_PATH		=	obj/

# OBJ				=	$(addprefix $(OBJ_PATH), $(OBJ_NAME))

# NAME			=	cub3D

# CC				=	cc

# RM				=	rm -rf

# FLAG			=	-Wall -Wextra -Werror -g3 #-fsanitize=address

# LIBFT			=	libft/libft.a

# MINILIBX		=	minilibx/libmlx.a

# FRAMEWORK		=	-lX11 -lXext -L minilibx/ -lmlx -lm -pthread -lbsd

# all: $(LIBFT) $(OBJ_PATH) $(MINILIBX) $(NAME)
# 	@:
	
# $(LIBFT) :
# 	@make -C libft/

# $(MINILIBX) :
# 	make -C minilibx/

# $(NAME): $(OBJ_NAME) $(HEADER)
# 	@gcc $(FLAG) $(LIBFT) $(MINILIBX) $(OBJ_NAME) -o $(NAME)
# 	@printf "	\033[2K\r$(DARK_BLUE)cube3D\t:\t$(LIGHT_GREEN)Updated\n\033[0m"

# $(OBJ_PATH):
# 	@mkdir -p obj/ 2> /dev/null
# 	@mkdir -p obj/convert 2> /dev/null
# 	@mkdir -p obj/cub 2> /dev/null
# 	@mkdir -p obj/parsing 2> /dev/null
# 	@mkdir -p obj/display 2> /dev/null

# $(OBJ_PATH)%.o: $(SRC_PATH)%.c $(HEADER) Makefile
# 	@printf "\033[2K\r$(LIGHT_RED)Compiling...	\033[37m$<\033[36m \033[0m"
# 	@gcc $(FLAG) -I $(HEADER) -I minilibx -c $< -o $@

# clean:
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/.	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/..	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/...	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/.	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/..	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Deleting cub3D srcs/...	\033[37m"
# 	@sleep 0.1
# 	@${RM} ${OBJ_PATH} cube3D.dSYM
# 	@printf "\33[2K\r$(LIGHT_RED)Deleted successfully!\n\033[0m"

# fclean: clean
# 	@${RM} ${NAME}
# 	@make -C libft/ fclean
# 	@make -C minilibx/ clean

# re: fclean all

# norme:
# 	@norminette $(SRC_PATH) $(HEADER)

# normed:

# 	@norminette $(SRC_PATH) $(HEADER)
# 	@$(MAKE) continue
# 	@echo ""
# 	@git add .
# 	@git commit -m "normed" 1>/dev/null
# 	@printf "\33[2K\r$(YELLOW)Push on repositories ?\n\033[0m"
# 	@$(MAKE) continue
# 	@echo ""
# 	@$(MAKE) push

# push:

# 	@printf "\33[2K\r$(LIGHT_RED)Pushing 	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Pushing .	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Pushing ..	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Pushing ...	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Pushing 	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Pushing .	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Pushing ..	\033[37m"
# 	@sleep 0.1
# 	@printf "\33[2K\r$(LIGHT_RED)Pushing ...	\033[37m"
# 	@sleep 0.1
# 	@git push github master 2>/dev/null
# 	@printf "\33[2K\r$(FLASH_GREEN)Pushed successfully on github !\n\033[0m"
# 	@git push origin master 2>/dev/null
# 	@printf "\33[2K\r$(FLASH_GREEN)Pushed successfully on vogsphere !\n\033[0m"

# lib:
# 	@make -C libft/

# relib:
# 	@$(MAKE) fclean
# 	@make -C libft/ re
# 	@$(MAKE) all

# continue:
# 	@echo ""
# 	@while [ -z "$$CONTINUE" ]; do \
# 		read -r -p "Press [y/N] to continue : " CONTINUE; \
# 	done ; \
# 	[ $$CONTINUE == "y" ] || [ $$CONTINUE == "Y" ] || (echo "Exiting ..."; $(MAKE) ew ; exit 1 2> /dev/null)

# git-%:
# 	@$(MAKE) norme
# 	@$(MAKE) continue
# 	@echo ""
# 	@git add .
# 	@git status
# 	@$(MAKE) continue
# 	@echo ""
# 	@printf "\33[2K\r$(FLASH_GREEN)Commit name :\t[$(@:git-%=%)]\n\033[0m"
# 	@$(MAKE) continue
# 	@git commit -m "$(@:git-%=%)" 1>/dev/null
# 	@printf "\33[2K\r$(YELLOW)\nPush on repositories ?\033[0m"
# 	@echo ""
# 	@$(MAKE) continue
# 	@echo ""
# 	@$(MAKE) push
# 	@echo ""
# 	@printf "\33[2K\r$(GREEN)Everything done\n\n\033[0m"

# call: all
# 	@nm -g $(addprefix ${OBJ_PATH}, ${OBJ_NAME})

# ew:
# 	@say -v Fiona ew

# full_check: all
# 	@$(MAKE) norme
# 	@$(MAKE) continue
# 	@echo ""
# 	@$(MAKE) call
# 	@$(MAKE) continue
# 	@echo ""
# 	@$(MAKE) relib
# 	@printf "\33[2K\r$(FLASH_GREEN)\nCommit ?\n\033[0m"
# 	@$(MAKE) continue
# 	@echo ""
# 	@git add .
# 	@git commit -m "full checked" 1>/dev/null
# 	@printf "\33[2K\r$(YELLOW)Push on repositories ?\n\033[0m"
# 	@$(MAKE) continue
# 	@echo ""
# 	@$(MAKE) push

#####################################################################################################

LIBFT_PATH =	./libft
MINILIBX_PATH =	./minilibx
HEADERS =	includes/ft_cub3d.h
OBJ =	$(SRCS:.c=.o) libft/libft.a minilibx/libmlx.a
NAME =	Cub3D
CC =	gcc
CFLAGS =	-Wall -Wextra -Werror -g3
MLXFLAGS =	-lX11 -lXext -L minilibx/ -lmlx -lm -pthread -lbsd
RM =	rm -f

all :	libft_all minilibx_all ${NAME}
		@

$(NAME) :		$(OBJ)
					@$(CC) $(CFLAGS) -o $@ $(OBJ) $(MLXFLAGS)

%.o :			%.c $(HEADERS)
					@$(CC) $(CFLAGS) -o $@ -c $<

clean :			libft_clean minilibx_clean
					@$(RM) -f $(OBJ)

fclean 	:		clean libft_fclean
					@$(RM) ${NAME}

re :			fclean all


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