# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: soelalou <soelalou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/02 19:46:45 by soelalou          #+#    #+#              #
#    Updated: 2024/04/18 09:15:55 by soelalou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# VARIABLES

NAME        = cub3D
LIBFT		= libft/libft.a
CC          = cc
CFLAGS      = -Wall -Wextra -Imlx -Iinc -g3
MLXFLAGS    = -Lmlx -lXext -lX11 -lmlx
RM          = rm -rf

SRCS_DIR    = src
OBJS_DIR    = bin

SRCS        = $(shell find $(SRCS_DIR) -type f -name '*.c')
OBJS        = $(patsubst src/%.c, $(OBJS_DIR)/%.o, $(SRCS))

# **************************************************************************** #
# COLORS

GREEN       = \033[0;32m
GREY        = \033[1;30m
PURPLE      = \033[0;35m
BLUE        = \033[0;94m
CYAN        = \033[0;36m
PINK        = \033[1;35m
RED         = \033[0;31m
END_COLOR   = \033[0;39m


# **************************************************************************** #
# RULES

all: dependencies $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(MLXFLAGS)
	@echo "$(GREEN)[Success]$(END_COLOR) Cub3D is ready !"

$(OBJS_DIR)/%.o: src/%.c
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) -c $< -o $@

dependencies:
	@make -s -C mlx
	@echo "$(RED)[Dependencies]$(END_COLOR) MiniLibX is ready !"
	@make -s -C libft

clean:
	@$(RM) $(OBJS_DIR)
	@make clean -s -C libft
	@make clean -s -C mlx
	@echo "$(GREY)[Clean]$(END_COLOR) Objects have been deleted"

fclean: clean
	@$(RM) $(OBJS_DIR) $(NAME) a.out
	@make fclean -s -C libft
	@echo "$(GREY)[Clean]$(END_COLOR) $(NAME) and executables have been deleted"

re: fclean all
	@echo "$(PURPLE)[Rebuild]$(END_COLOR) Done."

.PHONY: all clean fclean re