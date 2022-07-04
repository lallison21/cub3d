NAME		=	cub3D

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
LIB			=	-L libft -lft
MLX			=	-L minilibx -lmlx -framework OpenGL -framework AppKit

SRCS_DIR	=	sources/
UTILS_DIR	=	utils/
HEADER		=	incudes/cud3d.h

SRCS		=	$(addprefix $(SRCS_DIR),	main_cub3d.c	fill_node.c)
UTILS		=	$(addprefix $(UTILS_DIR),	error_msg.c		check_utils.c	\
											free_memory_utils.c)

OBJS		=	$(SRCS:%.c=%.o) $(UTILS:%.c=%.o)

WHITE   	=	\033[0m
BLACK   	=	\033[0;30m
RED     	=	\033[0;31m
GREEN   	=	\033[0;32m
YELLOW  	=	\033[0;33m
BLUE    	=	\033[0;34m
MAGENTA 	=	\033[0;35m
CYAN    	=	\033[0;36m

.PHONY		:	all clean fclean re

all			:	$(NAME)

$(NAME)		:	$(OBJS)
				@make -C minilibx
				@make -C libft
				@echo "[$(BLUE)CUB3D$(WHITE)] OBJECT FILES CREATED\n\c"
				@$(CC) $(CFLAGS) $(LIB) $(MLX) $(OBJS) -o $(NAME)
				@echo "[$(BLUE)CUB3D$(WHITE)] EXECUTABLE FILE CREATED\n\c"
				@make -C . clean

%.o			:	%.c $(HEADER)
				@$(CC) $(CFLAGS) -I minilibx mlx -c $< -o $(NAME)
				@echo "$(GREEN)❱$(WHITE)\n\c"

clean		:
				@make -C libft clean
				@$(RM) $(OBJS)
				@echo "$(YELLOW)Object files deleted$(WHITE)"

fclean		:	clean
				@make -C minilibx clean
				@make -C libft fclean
				@$(RM) $(NAME)
				@echo "$(YELLOW)Executable file deleted$(WHITE)"

re			:	fclean all