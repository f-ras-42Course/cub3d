
NAME = cub3d
CC = cc
CFLAGS = -Werror -Wextra -Wall -Ofast -flto -march=native
MLX42_FLAGS = -ldl -lglfw -pthread -lm
INCLUDE = -I include -I $(MLX42_DIR)/include
SRC_DIR = src
OBJ_DIR = obj
SOURCES = $(shell find $(SRC_DIR) -type f -name "*.c")
OBJECTS = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SOURCES:%.c=%.o))
RM = rm -f

# Libraries
LIB_DIR = lib
MLX42 = $(LIB_DIR)/libmlx42.a
MLX42_DIR = $(LIB_DIR)/MLX42
MLX42_BUILD = $(MLX42_DIR)/build
MLX42_CMAKE = $(MLX42_DIR)/CMakeLists.txt

ifdef DEBUG
CFLAGS += -g -D DEBUG=-1
MLX42_DEBUG = -DDEBUG=1
endif

ifdef FSAN
CFLAGS += -fsanitize=address -g
endif

# Targets
.PHONY: all mandatory bonus clean fclean re directories debug rebug fsan resan message

all: $(NAME)

$(NAME): $(MLX42_CMAKE) $(MLX42) $(OBJECTS)
	$(CC) $(OBJECTS) $(MLX42) $(MLX42_FLAGS) $(CFLAGS) -o $@
	@$(MAKE) message EXECUTABLE=$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(MAKE) directories
	$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

bonus: all

# Libraries
$(MLX42_CMAKE):
	$(MAKE) init_subm

$(MLX42):
	cmake -S $(MLX42_DIR) -B $(MLX42_BUILD) $(MLX42_DEBUG)
	make -C $(MLX42_BUILD) -j4
	cp $(MLX42_BUILD)/$(@F) $@
	@echo "\033[92mMLX library available in ./$(MLX42)\033[0m"

# Directories
directories:
	@find $(SRC_DIR) -type d | sed 's/$(SRC_DIR)/$(OBJ_DIR)/' | xargs mkdir -p

# Cleaning
clean:
	$(RM) -r obj

fclean: clean
	$(RM) $(MLX42)
	$(RM) -rf $(MLX42_BUILD)
	$(RM) $(NAME)

re: fclean all

ree: clean
	$(RM) $(NAME)
	$(MAKE)

#Options

# Debugging
debug:
	$(MAKE) DEBUG=1 

rebug: fclean debug

fsan:
	$(MAKE) FSAN=1

resan: fclean fsan

# Info Message
message:
	@echo "\033[92m$(EXECUTABLE) is ready for usage!\033[0m"

# Submodule functions
init_subm:
	git submodule update --init --recursive
	git submodule foreach --recursive git checkout master

update_subm:
	git submodule update --recursive
	git submodule foreach --recursive git fetch
	git submodule foreach git merge origin master

##########################################
#										 #
# Optimize //-- (now default mode)		 #
#										 #
# ifdef OPTIM							 #
# CFLAGS += -Ofast -flto -march=native	 #
# endif									 #
#										 #
# optim:								 #
# 	$(MAKE) OPTIM=1						 #
# roptim: fclean optim					 #
#										 #
##########################################