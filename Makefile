NAME	=	cub3D

NAME_B	=	cub3D_bonus

SRCS	=	mandatory/cub3d.c			mandatory/map_creation.c	mandatory/commands.c\
			mandatory/config_check.c	mandatory/config_check2.c	mandatory/map_check.c\
			mandatory/raycaster.c		mandatory/raycaster2.c		mandatory/raycaster3.c\
			mandatory/utils.c			mandatory/utils2.c			mandatory/utils3.c\
			mandatory/movements.c		mandatory/finding_assets.c

SRCS_B	=	bonus/cub3d.c			bonus/map_creation.c	bonus/utils.c\
			bonus/config_check.c	bonus/config_check2.c	bonus/map_check.c\
			bonus/raycaster.c		bonus/raycaster2.c		bonus/raycaster3.c\
			bonus/commands.c		bonus/utils2.c			bonus/utils3.c\
			bonus/movements.c		bonus/movements2.c		bonus/finding_assets.c\
			bonus/minimap.c


HEADER		=	mandatory/cub3d.h
HEADER_B	=	bonus/cub3d.h
OBJ			=	$(SRCS:%.c=%.o)
OBJ_B		=	$(SRCS_B:%.c=%.o)

CC		=	cc
CFLAGS	=	-Wall -Wextra -Werror

.PHONY	:	all clean fclean re bonus

all		:	$(NAME)

$(NAME)	:	$(OBJ) $(HEADER)
	@make -C minilibx
	$(CC) $(CFLAGS) -I$(HEADER) $(OBJ) -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(NAME_B)	:	$(OBJ_B) $(HEADER_B)
	@make -C minilibx
	$(CC) $(CFLAGS) -I$(HEADER_B) $(OBJ_B) -L minilibx -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

bonus	:	$(NAME_B)

%.o : %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@


clean	:
	@rm -f $(OBJ) $(OBJ_B)

fclean	:	clean
	@make -C minilibx clean
	@$(RM) $(NAME) $(NAME_B)

re		:	fclean all
