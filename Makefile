###########################
###### MAIN SETTINGS ######
###########################

# Compiler to be used
CC				:= clang

# Compiler flags
CFLAGS			:= -Wall -Werror -Wextra -pedantic -O3

# Path to the Minilibx directory
MLX_DIR        := minilibx-linux/

# Minilibx library file
MLX_LIB        := $(MLX_DIR)/libmlx.a

# Libraries to be linked (if any)
LIBS			:= -lXext -lX11 -L$(MLX_DIR) -lmlx -lm

# Include directories
INCLUDES		:= -Iinc/ -I$(MLX_DIR)

# Target executable
TARGET			:= cub3D

# Source files directory
SRC_DIR			:= src/

# Source files
SRC_FILES       += main.c

SRC_FILES       += core/f_gc_clean.c
SRC_FILES       += core/f_graceful_exit.c
SRC_FILES       += core/f_gc_malloc.c
SRC_FILES       += core/f_print_error.c
SRC_FILES       += core/f_init.c

SRC_FILES       += parsing/f_check_args.c
SRC_FILES       += parsing/f_is_config_complete.c
SRC_FILES       += parsing/f_check_for_invalid_map_lines.c
SRC_FILES       += parsing/f_is_map_line.c
SRC_FILES       += parsing/f_check_open_walls.c
SRC_FILES       += parsing/f_set_color_config.c
SRC_FILES       += parsing/f_check_single_starting_pos.c
SRC_FILES       += parsing/f_set_config_data.c
SRC_FILES       += parsing/f_create_map_array.c
SRC_FILES       += parsing/f_set_input_line_type.c
SRC_FILES       += parsing/f_fill_map_array.c
SRC_FILES       += parsing/f_set_map.c
SRC_FILES       += parsing/f_handle_cub_file.c
SRC_FILES       += parsing/f_set_map_dimensions.c
SRC_FILES       += parsing/f_import_cub_file.c
SRC_FILES       += parsing/f_set_texture_path.c
SRC_FILES       += parsing/f_extract_player_pos.c
SRC_FILES       += parsing/f_load_textures.c

SRC_FILES       += utils/f_bzero.c
SRC_FILES       += utils/f_memcpy.c
SRC_FILES       += utils/f_strchr.c
SRC_FILES       += utils/f_strlen.c
SRC_FILES       += utils/f_char_count.c
SRC_FILES       += utils/f_readfile.c
SRC_FILES       += utils/f_strcmp.c
SRC_FILES       += utils/f_strscmp.c
SRC_FILES       += utils/f_split.c
SRC_FILES       += utils/f_strdup.c
SRC_FILES       += utils/f_is_dig.c
SRC_FILES       += utils/f_splitlines.c
SRC_FILES       += utils/f_strjoin.c

SRC_FILES       += debug/f_print_map.c
SRC_FILES       += debug/f_debug_info.c

SRC_FILES       += rendering/f_draw_minimap.c
SRC_FILES       += rendering/f_clear_image.c
SRC_FILES       += rendering/f_distance.c
SRC_FILES       += rendering/f_game_loop.c
SRC_FILES       += rendering/f_draw_square.c
SRC_FILES       += rendering/f_start_mlx.c
SRC_FILES       += rendering/f_key_press.c
SRC_FILES       += rendering/f_key_release.c
SRC_FILES       += rendering/f_move_player.c
SRC_FILES       += rendering/f_put_pixel.c
SRC_FILES       += rendering/f_handle_close_button.c
SRC_FILES       += rendering/f_draw_full_square.c
SRC_FILES       += rendering/f_draw_circle_full.c
SRC_FILES       += rendering/f_attempt_move.c
SRC_FILES       += rendering/f_next_grid_hit.c
SRC_FILES       += rendering/f_find_targets.c
SRC_FILES       += rendering/f_is_round.c
SRC_FILES       += rendering/f_is_wall.c
SRC_FILES       += rendering/f_draw_walls.c
SRC_FILES       += rendering/f_cosine_distance.c
SRC_FILES       += rendering/f_next_wall_hit.c
SRC_FILES       += rendering/f_get_texture.c


# Object files directory
OBJ_DIR			:= obj/

# Object files
OBJ_FILES		:= $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC_FILES))

# Dependency files directory
DEP_DIR			:= dep/

# Dependency files
DEPENDS			:= $(patsubst %.o, $(DEP_DIR)%.d, $(OBJ_FILES))
-include $(DEPENDS)


############################
###### SHELL COMMANDS ######
############################

RM				:= /bin/rm -f
MKDIR			:= /bin/mkdir -p
TOUCH			:= /bin/touch



############################
###### DEBUG SETTINGS ######
############################

ifeq ($(DEBUG), 1)
	CFLAGS		+= -g3 -O0
endif


################################
###### TARGET COMPILATION ######
################################

.DEFAULT_GOAL	:= all

all: $(TARGET) ## Build this project

# Compilation rule for object files
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(MKDIR) $(@D)
	@echo -n "[build] "
	$(CC) $(CFLAGS) -MMD -MF $(patsubst %.o, %.d, $@) $(INCLUDES) -c $< -o $@

# Rule for linking the target executable
$(TARGET): $(MLX_LIB) $(OBJ_FILES)
	@echo -n "[link] "
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ_FILES) $(INCLUDES) $(LIBS)
	-@echo -n "🚀 $(MAGENTA)" && ls -lah $(TARGET) && echo -n "$(RESET)"


####################################
###### LOCAL LIBS COMPILATION ######
####################################

$(MLX_LIB):
	@echo -n "[build] Minilibx library\n"
	@$(MAKE) -C $(MLX_DIR)


##############################
###### ADDITIONAL RULES ######
##############################

clean: ## Clean objects and dependencies
	@echo -n "[clean] "
	$(RM) $(OBJ_FILES)
	@echo -n "[clean] "
	$(RM) -r $(OBJ_DIR)
	@echo -n "[clean] "
	$(RM) $(DEPENDS)
	@echo -n "[clean] "
	$(RM) -r $(DEP_DIR)

fclean: clean ## Restore project to initial state
	@echo -n "[fclean] "
	$(RM) $(TARGET)

re: fclean all ## Rebuild project

help: ## Show help info
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | sort | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "$(CYAN)%-30s$(RESET) %s\n", $$1, $$2}'

.PHONY: all re clean fclean help


####################
###### COLORS ######
####################
# Color codes
RESET		:= \033[0m
BOLD		:= \033[1m
UNDERLINE	:= \033[4m

# Regular colors
BLACK		:= \033[30m
RED			:= \033[31m
GREEN		:= \033[32m
YELLOW		:= \033[33m
BLUE		:= \033[34m
MAGENTA		:= \033[35m
CYAN		:= \033[36m
WHITE		:= \033[37m

# Background colors
BG_BLACK	:= \033[40m
BG_RED		:= \033[41m
BG_GREEN	:= \033[42m
BG_YELLOW	:= \033[43m
BG_BLUE		:= \033[44m
BG_MAGENTA	:= \033[45m
BG_CYAN		:= \033[46m
BG_WHITE	:= \033[47m

# This was adapted from: https://github.com/tesla33io/awesome_makefile