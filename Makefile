# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/23 18:24:40 by ana-cast          #+#    #+#              #
#    Updated: 2024/02/07 19:06:53 by ana-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = push_swap
CHECKER = checker
LIBFT = libft/
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
INCLUDE = -L ./libft -lft

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

SRCS_PS = src/push_swap.c

SRCS = src/operations/swap.c src/operations/push.c \
	src/operations/rotate.c src/operations/rrotate.c \
	src/algorithm/sorting_stack.c src/algorithm/sorting_big.c \
	src/algorithm/sorting_calculations.c src/algorithm/sorting_utils.c \
	src/utils/utils_init_stack.c src/utils/utils_stack.c src/utils/utils.c \
	src/utils/utils_process_input.c

SRCS_BON = src/checker/checker_bonus.c

OBJECTS_PS = $(SRCS_PS:.c=.o)

OBJECTS = $(SRCS:.c=.o)

OBJECTS_BON = $(SRCS_BON:.c=.o)

################################################################################
##                                    COLOURS                                 ##
################################################################################

COLOUR_GREEN=\033[0;32m
COLOUR_RED=\033[0;31m
COLOUR_BLUE=\033[0;34m
COLOUR_YELLOW= \033[33m
COLOUR_MAGENTA=\033[35m
COLOUR_TURQUOISE=\033[36m	
COLOUR_END=\033[0m

################################################################################
##                                     RULES                                  ##
################################################################################

all : head $(NAME)

head : 
	@echo "$(COLOUR_MAGENTA)"
	@echo "                    _                                  "
	@echo "                   | |                                 "
	@echo " _ __   _   _  ___ | |__    ___ __      __ __ _  _ __  "
	@echo "| '_ \ | | | |/ __|| '_ \  / __|\ \ /\ / // _\` || '_ \ "
	@echo "| |_) || |_| |\__ \| | | | \__ \ \ V  V /| (_| || |_) |"
	@echo "| .__/  \__,_||___/|_| |_| |___/  \_/\_/  \__,_|| .__/ "
	@echo "| |                    ______                   | |    "
	@echo "|_|                   |______|                  |_|    "
	@echo "        42MLG: by ana-cast \n"
	@echo "Proyect: \033[36m push_swap $(COLOUR_MAGENTA)"
	@echo "Commands:\033[36m all clean fclean re bonus$(COLOUR_END)\n"

$(NAME) : $(OBJECTS_PS) $(OBJECTS)
	@make -C $(LIBFT)
	@printf " ⏱  Creating $(NAME)"
	@$(CC) $(FLAGS) $(OBJECTS_PS) $(OBJECTS) -o $(NAME) $(INCLUDE)
	@echo "$(COLOUR_GREEN)\r  ✓   Created  $(NAME) $(COLOUR_END)\n"

bonus : head_bon $(OBJECTS_BON) $(OBJECTS)
	@make -C $(LIBFT)
	@$(CC) $(FLAGS) $(OBJECTS_BON) $(OBJECTS) -o $(CHECKER) $(INCLUDE)

head_bon : 
	@echo "$(COLOUR_MAGENTA)"
	@echo "      _               _             "
	@echo "     | |             | |            "
	@echo "  ___| |__   ___  ___| | _____ _ __ "
	@echo " / __| '_ \ / _ \/ __| |/ / _ \ '__|"
	@echo "| (__| | | |  __/ (__|   <  __/ |   "
	@echo " \___|_| |_|\___|\___|_|\_\___|_|   "
	@echo "               42MLG: by ana-cast \n"
	@echo "Proyect: \033[36m push_swap checker $(COLOUR_MAGENTA)"
	@echo "Commands:\033[36m all clean fclean re bonus$(COLOUR_END)\n"

%.o : %.c
	@printf " ⏱  Compiling $@"
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "$(COLOUR_GREEN)\r  ✓   Compiled  $@ $(COLOUR_END)"

clean :
	@printf "\n$(COLOUR_YELLOW) 🗑   Removing objects$(COLOUR_END)"
	@$(RM) $(OBJECTS_PS) $(OBJECTS) $(OBJECTS_BON)
	@make clean -C $(LIBFT)
	@echo "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  objects $(COLOUR_END)"

fclean: clean
	@printf "$(COLOUR_YELLOW) 🗑   Removing $(NAME)$(COLOUR_END)"
	@$(RM) $(NAME) $(CHECKER)
	@make fclean -C $(LIBFT)
	@echo "$(COLOUR_GREEN)\r  ✓  $(COLOUR_RED)Removed  $(NAME) and libft $(COLOUR_END)\n"

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

.PHONY: all clean fclean re bonus