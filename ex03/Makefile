NAME = fixed

CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

OBJ_DIR = .obj

SRCS = src/Fixed.cpp src/Point.cpp
OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:%.cpp=%.o))

HEADERS = inc/Fixed.hpp inc/Point.hpp

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

.PHONY: all clean fclean re

# good website to visualize data in a grid
# https://www.geogebra.org/m/JMMKv7cx