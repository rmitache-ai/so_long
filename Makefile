# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmitache <rmitache@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/11 16:16:39 by rmitache          #+#    #+#              #
#    Updated: 2023/10/28 07:28:43 by rmitache         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[32m
YELLOW = \033[33m
CYAN = \033[36m
MAGENTA = \033[35m
RESET = \033[0m

NAME = so_long
BONUS = so_long_bonus
FLAGS =

SRC = check_map.c free.c get_next_line_utils.c get_next_line.c image.c \
		so_long.c map.c player_movement.c window.c
OBJ = $(SRC:.c=.o)

B_SRC = bonus/bonus_check_map.c bonus/bonus_free.c bonus/bonus_image.c \
		bonus/bonus_map.c bonus/bonus_moves_on_screen.c bonus/bonus_so_long.c \
		bonus/bonus_window.c bonus/bonus_get_next_line_utils.c bonus/bonus_get_next_line.c \
		bonus/bonus_player_movement.c
B_OBJ = $(B_SRC:.c=.o)

LIBFT_PATH = "libft/"
LIBFT_A = "libft/libft.a"
PRINTF_PATH = "ft_printf/"
MLX_PATH = "mlx/"
PRINTF_A = "ft_printf/libftprintf.a"
INCLUDE = -I mlx -L mlx -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(YELLOW)Building Wizard in Dungeon: DN Edition, please wait.$(RESET)"
	make -C $(LIBFT_PATH)
	@echo "$(GREEN)✔️  Generating the needed Library 1/3$(RESET)"
	make -C $(PRINTF_PATH)
	@echo "$(GREEN)✔️  Generating the needed Library 2/3$(RESET)"
	make -C $(MLX_PATH)
	@echo "$(GREEN)✔️  Generating the needed Library 3/3$(RESET)"
	gcc $(FLAGS) $(SRC) $(INCLUDE) $(LIBFT_A) $(PRINTF_A) -o $(NAME)
	@echo "$(CYAN)🚀  Build Complete! Have fun playing the game!$(RESET)"

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC)


bonus: $(B_OBJ)
	gcc $(FLAGS) $(B_SRC) $(INCLUDE) $(LIBFT_A) $(PRINTF_A) -o $(BONUS)

bonus/%.o: bonus/%.c
	gcc $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ)
	@rm -rf $(B_OBJ)
	@make -C $(LIBFT_PATH) clean
	@make -C $(PRINTF_PATH) clean
	@make -C $(MLX_PATH) clean
	@echo "$(MAGENTA)🧹  Cleaned up object files and libraries.$(RESET)"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(BONUS)
	@make -C $(LIBFT_PATH) fclean
	@make -C $(PRINTF_PATH) fclean
	@make -C $(MLX_PATH) clean
	@echo "$(MAGENTA)🗑️  Removed executable and all libraries.$(RESET)"

re: fclean all

.PHONY: all clean fclean re