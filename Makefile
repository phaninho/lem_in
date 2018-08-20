
NAME = lem-in

SRC_PATH = ./src/
OBJ_PATH = ./obj/
INC_PATH = ./include/ ./libft/
LIB_PATH = ./libft/

SRC_NAME = file_reader.c error_handler.c data_loader.c node_handler.c \
			init.c path_controller.c
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = -lft
DEP = ./include/lem_in.h

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))
LIB = $(addprefix -L,$(LIB_PATH))

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: lib
	@echo "\033[37;44m Make $(NAME) \033[0m"
	@make $(NAME)

$(NAME): $(OBJ)
	$(CC) $(INC) $^ -o $@ $(LIB) $(LIB_NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(DEP)
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

.PHONY: lib clean fclean re

lib:
	@echo "\033[37;44m Make libft \033[0m"
	@make -C $(LIB_PATH)

clean:
	rm -rf $(OBJ) $(OBJ_PATH)

fclean: clean
	@make -C $(LIB_PATH) fclean
	rm -f $(NAME) $(LINK) $(TEST_NAME)


re: fclean all
