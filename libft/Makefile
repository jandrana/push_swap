# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-cast <ana-cast@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/15 21:00:35 by ana-cast          #+#    #+#              #
#    Updated: 2024/02/01 14:24:37 by ana-cast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


################################################################################
##                               COMPILATION INFO                             ##
################################################################################

NAME = libft.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

################################################################################
##                              SOURCES AND OBJECTS                           ##
################################################################################

CC_SRCS = functions/originals/character_classification/ft_isascii.c \
	functions/originals/character_classification/ft_isdigit.c \
	functions/originals/character_classification/ft_isprint.c \
	functions/originals/character_classification/ft_isalnum.c \
	functions/originals/character_classification/ft_isalpha.c \
	functions/originals/character_classification/ft_str_is_alpha.c \
	functions/originals/character_classification/ft_str_is_numeric.c \
	functions/originals/character_classification/ft_str_is_printable.c

CC2_SRCS = functions/originals/case_conversion/ft_tolower.c \
	functions/originals/case_conversion/ft_toupper.c

MM_SRCS = functions/originals/memory_manipulation/ft_bzero.c \
	functions/originals/memory_manipulation/ft_calloc.c \
	functions/originals/memory_manipulation/ft_strdup.c \
	functions/originals/memory_manipulation/ft_memcmp.c \
	functions/originals/memory_manipulation/ft_memcpy.c \
	functions/originals/memory_manipulation/ft_memmove.c \
	functions/originals/memory_manipulation/ft_memset.c \
	functions/originals/memory_manipulation/ft_memchr.c

SM_SRCS = functions/originals/string_manipulation/ft_atoi.c \
	functions/originals/string_manipulation/ft_atol.c \
	functions/originals/string_manipulation/ft_strlcat.c \
	functions/originals/string_manipulation/ft_strlcpy.c \
	functions/originals/string_manipulation/ft_strlen.c

SS_SRCS = functions/originals/string_search/ft_strchr.c \
	functions/originals/string_search/ft_strncmp.c \
	functions/originals/string_search/ft_strnstr.c \
	functions/originals/string_search/ft_strrchr.c

A_SRCS = functions/additionals/ft_itoa.c \
	functions/additionals/ft_split.c \
	functions/additionals/ft_striteri.c \
	functions/additionals/ft_strjoin.c \
	functions/additionals/ft_strmapi.c \
	functions/additionals/ft_strtrim.c \
	functions/additionals/ft_substr.c

AO_SRCS = functions/additionals/output_functions/ft_putchar_fd.c \
	functions/additionals/output_functions/ft_putendl_fd.c \
	functions/additionals/output_functions/ft_putnbr_fd.c \
	functions/additionals/output_functions/ft_putstr_fd.c
	
PF_SRCS = ft_printf/ft_printf_utils.c \
	ft_printf/ft_printf.c

GNL_SRCS = get_next_line/get_next_line.c \
	get_next_line/get_next_line_utils.c

CC_OBJECTS = $(CC_SRCS:.c=.o)
CC2_OBJECTS = $(CC2_SRCS:.c=.o)
MM_OBJECTS = $(MM_SRCS:.c=.o)
SM_OBJECTS = $(SM_SRCS:.c=.o)
SS_OBJECTS = $(SS_SRCS:.c=.o)
A_OBJECTS = $(A_SRCS:.c=.o)
AO_OBJECTS = $(AO_SRCS:.c=.o)
PF_OBJECTS = $(PF_SRCS:.c=.o)
GNL_OBJECTS = $(GNL_SRCS:.c=.o)

OBJECTS = $(CC_OBJECTS) $(CC2_OBJECTS) $(MM_OBJECTS) $(SM_OBJECTS) $(SS_OBJECTS) $(A_OBJECTS) $(AO_OBJECTS) $(PF_OBJECTS) $(GNL_OBJECTS)

BONUS_SR = functions/bonus/ft_lstadd_back_bonus.c \
	functions/bonus/ft_lstadd_front_bonus.c \
	functions/bonus/ft_lstclear_bonus.c \
	functions/bonus/ft_lstdelone_bonus.c \
	functions/bonus/ft_lstiter_bonus.c \
	functions/bonus/ft_lstlast_bonus.c \
	functions/bonus/ft_lstnew_bonus.c \
	functions/bonus/ft_lstsize_bonus.c \
	functions/bonus/ft_lstmap_bonus.c \
	get_next_line/get_next_line_bonus.c
	
BONUS_OB = $(BONUS_SR:.c=.o)

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

all : $(NAME)

$(NAME) : $(OBJECTS)
	@printf "\n ⏱  Creating $(NAME)"
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)
	@echo "$(COLOUR_GREEN)\r  ✓   Created  $(NAME) $(COLOUR_END)\n"

bonus : bon_head $(OBJECTS) $(BONUS_OB)
	@printf "\n  🤑  Creating BONUS $(NAME)"
	@ar rc $(NAME) $(OBJECTS) $(BONUS_OB)
	@ranlib $(NAME)
	@echo "$(COLOUR_GREEN)\r  ✓  Created  BONUS $(NAME) $(COLOUR_END)\n"

%.o : %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJECTS) $(BONUS_OB)

fclean: clean
	@$(RM) $(NAME)

re :
	@$(MAKE) fclean
	@clear
	@$(MAKE) all

rebonus :
	@$(MAKE) fclean
	@clear
	@$(MAKE) bonus

.PHONY: all bonus clean fclean re rebonus