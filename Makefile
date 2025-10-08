# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchanlia <mchanlia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/11 14:54:32 by mchanlia          #+#    #+#              #
#    Updated: 2025/09/11 14:54:32 by mchanlia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                Target                                        #
# **************************************************************************** #

NAME = philo

# **************************************************************************** #
#                                Compiler + Flags                              #
# **************************************************************************** #

CC = cc
FLAGS = -pthread -Wall -Wextra -Werror -g3 -O0 
INCLUDES = -I./includes 
INCLUDES_BONUS = -I./bonus

# **************************************************************************** #
#                                Directories                                   #
# **************************************************************************** #

SRC_DIR = srcs
SHARED_DIR = 
OBJ_DIR = obj
LIBFT_DIR = 
BONUS_DIR = bonus

# **************************************************************************** #
#                                Source Files                                  #
# **************************************************************************** #

SRC = $(addprefix $(SRC_DIR)/, main.c check_args.c utils.c fork_init.c \
								init_philos.c init_thread.c philos_func.c \
								free_struct.c get_time_usleep.c print_msg.c \
								 mutexes_check.c mutexes_check2.c)
SHARED = $(addprefix $(SHARED_DIR)/, )
BONUS_SRC = $(addprefix $(BONUS_DIR)/, )
# **************************************************************************** #
#                                Objects                                       #
# **************************************************************************** #

Objects = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
SHARED_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SHARED:.c=.o)))
BONUS_OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS_SRC:.c=.o)))

# **************************************************************************** #
#                                Printf                                        #
# **************************************************************************** #

PRINTF = 

# **************************************************************************** #
#                                Libft                                         #
# **************************************************************************** #

LIBFT = 

# **************************************************************************** #
#                                Rules                                         #
# **************************************************************************** #

all: $(NAME)

$(NAME): $(Objects) $(SHARED_OBJ)
# 	@make -C $(LIBFT_DIR)
# 	@make -C $(SHARED_DIR)
	$(CC) $(FLAGS) $(INCLUDES) $(Objects) $(SHARED_OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@ 
# si tu veux supprimer les flags c'est ici

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: $(SHARED_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

bonus: $(BONUS_OBJ) $(SHARED_OBJ)
	@make -C $(LIBFT_DIR)
	@make -C $(SHARED_DIR)
	$(CC) $(FLAGS) $(INCLUDES_BONUS) $(BONUS_OBJ) $(SHARED_OBJ) -o $(NAME)_bonus

# **************************************************************************** #
#                                CLEAN & RE                                    #
# **************************************************************************** #
clean: 
	rm -rf $(Objects) obj
# 	make clean -C Libft
# 	rm -rf $(LIBFT_DIR)/libft.a
# 	make clean -C minilibx-linux

fclean: clean
	rm -rf $(NAME) $(NAME)_bonus

re: fclean all
.PHONY: all clean fclean re