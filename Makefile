NAME := pipex

SRC:= $(addprefix $(SRC_DIR), pipex.c utils.c)
OBJ_DIR:= sources/.obj/
OBJ:= $(SRC:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)
DEPS:= $(OBJ:%.o=%.d)

CC:= cc
CCFLAGS:= -Wextra -Wall -Werror -g3
CPPFLAGS = -MMD -MP
SRC_DIR:= sources/
INCLUDES:= sources/

LIBFT_DIR := Libft/
LIBFT := $(LIBFT_DIR)libft.a
LIBFT_FLAG := -L $(LIBFT_DIR) $(LIBFT)

HEADERS:= -I $(INCLUDES) -I $(LIBFT_DIR)

all: $(NAME)

$(NAME): $(OBJ)
	$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CCFLAGS) $(OBJ) $(LIBFT_FLAG) -o $(NAME)
	@echo "👉 $(BLUE)$(CC) $(CCFLAGS) $(OBJ) $(LIBFT_FLAG) -o $(NAME)$(DEF_COLOR) 👀👀👀"
	@echo "$(GREEN) 💪💪💪💪💪💪👉 🦸🦸 $(NAME) compiled! 🦸🦸 💪💪💪💪💪💪 $(DEF_COLOR)"
	
$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@echo "✅ $(MAGENTA)Compiling: $< $(DEF_COLOR) ✅"
	$(CC) $(CCFLAGS) $(CPPFLAGS)  $(HEADERS) -o $@ -c $<

-include $(DEPS)
# Colors

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m




clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)💩💩💩💩💩💩💩 $(NAME) removed! 💩💩💩💩💩💩💩$(DEF_COLOR)"
	rm -f $(NAME)

re: fclean all

info:
	@echo "OBJ": $(OBJ)
	@echo "DEPS": $(DEPS)

.PHONY: all clean fclean re