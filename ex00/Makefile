NAME = fixed

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 #-fsanitize=address

OBJ_DIR = .obj
SRC_DIR = src
INC_DIR = inc

SRC_FILES = Fixed.cpp main.cpp
INC = Fixed.hpp

SRCS = $(addprefix $(SRC_DIR)/, $(SRC_FILES))
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))
HEADERS = $(addprefix $(INC_DIR)/, $(INC))

all: $(NAME)

$(NAME): $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -o $@
	@echo "Compiled!"

$(OBJ_DIR)/%.o: %.cpp $(HEADERS)
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS) $(OBJ_DIR)
	@echo "Removed object files"

fclean: clean
	@rm -rf $(NAME)
	@echo "Removed executable"

re: fclean all

val: all
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./$(NAME)

.PHONY: all clean fclean re val