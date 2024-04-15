NAME = philo

OBJ_PATH = tmp/

SRC = philo.c input_check.c

OBJ = $(addprefix $(OBJ_PATH), $(SRC:.c=.o))

CFLAGS = -I philo.h -Wall -Wextra -Werror -g -fsanitize=thread

#################################################################

# Regular Colors
BLACK := \033[0;30m
RED := \033[0;31m
GREEN := \033[0;32m
YELLOW := \033[0;33m
BLUE := \033[0;34m
MAGENTA := \033[0;35m
CYAN := \033[0;36m
WHITE := \033[0;37m

# Reset
RESET := \033[0m

#################################################################

all: tmp $(NAME)

tmp:
		@mkdir -p $(OBJ_PATH)

$(NAME): $(OBJ)
				@cc $(CFLAGS) $(OBJ) -o $(NAME)
				@echo "$(GREEN)Philo compiled$(RESET)"

$(OBJ_PATH)%.o:%.c
				@mkdir -p $(dir $@)
				@cc $(CFLAGS) -c $< -o $@
				@echo "$(CYAN)Compiling Philo:$(YELLOW) $@$(RESET)"

re: fclean all

clean:
				@rm -rf $(OBJ_PATH)
				@echo "$(CYAN)Philo $(YELLOW)- $(RED)Objs deleted$(RESET)"

fclean:	clean
				@rm -rf $(OBJ_PATH)
				@echo "$(CYAN)Philo $(RED)deleted$(RESET)"

.PHONY: all re clean fclean 
