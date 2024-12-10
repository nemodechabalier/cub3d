# Directories
INCLUDES_DIR = Includes
LIBFT_DIR = libft_all
MLX_DIR = mlx_linux
SRCS_DIR = Srcs
OBJ_DIR = obj

# Libraries
LIBFT_LIB = $(LIBFT_DIR)/libft_printf_gnl.a
MLX_LIB_LINUX = $(MLX_DIR)/libmlx.a
MLX_DIR = mlx_linux/
MLX_NAME = libmlx.a
MLX_LIBS = -L$(MLX_DIR)/libmlx.a -lmlx -lXext -lX11 -lm -lz
# Files
SRCS = $(shell find $(SRCS_DIR) -name "*.c")
OBJS = $(patsubst $(SRCS_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

# Compiler and flags
CC = cc
CFLAGS = -g3 -Wall -Wextra -Werror -I$(INCLUDES_DIR)
LDFLAGS = -lm -Lmlx_linux -lmlx -lXext -lX11 -lXrandr -lXrender -lz -lXcursor -lXinerama -lXft -DENVIRONMENT 

# Main executable
NAME = cub3d_bonus

# Rules
all: $(NAME)

$(NAME): $(LIBFT_LIB) $(MLX_LIB_LINUX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT_LIB) $(MLX_LIB_LINUX) $(LDFLAGS) -o $(NAME)

# Rule to create .o files and ensure directory structure in obj/
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c
	@mkdir -p $(dir $@)  # Create the necessary subdirectories
	$(CC) $(CFLAGS) -c $< -o $@

# Libraries
$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX_LIB_LINUX) $(MLX_LIB):
	$(MAKE) -C $(MLX_DIR)

# Cleaning rules
clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(MLX_DIR) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(MLX_LIB_LINUX) $(MLX_LIB)

re: fclean all

.PHONY: all clean fclean re
