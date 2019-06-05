NAME = fdf
CC = gcc

SRC_PATH = ./src/
OBJ_PATH = ./obj/
LIB_PATH = ./lib/
INC_PATH = ./include/ $(LIB_PATH)libft/include/

GCC_FLGS = -Werror -Wextra -Wall

SRC_NAME = main.c parser.c fdf.c bresenham.c draw.c isometric.c

GCC_LIBS = -lmlx -framework OpenGL -framework Appkit

OBJ_NAME = $(SRC_NAME:.c=.o)
	LIB_NAME = libft

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L$(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_PATH)libft
			$(CC) $(LIB) -lft $(INC) $(OBJ) $(GCC_LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
			$(CC)  $(INC) -o $@ -c $<

clean:
		rm -fv $(OBJ)
			make clean -C $(LIB_PATH)libft


fclean: clean
		make -C $(LIB_PATH)libft fclean
			rm -fv $(NAME)

re: fclean all
