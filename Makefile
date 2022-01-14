# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/14 18:57:39 by tgeorgin          #+#    #+#              #
#    Updated: 2022/01/14 19:36:50 by tgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

CC = gcc
FLAGS = -Wextra -Werror -Wall

LIBFT_A = libft.a
LIBF_DIR = libft/
LIBFT  = $(addprefix $(LIBF_DIR), $(LIBFT_A))

HEADER	= -I./includes/
SRC_DIR = src/

SRC_FILES = pipex.c utils.c 
OBJS = $(SRC_FILES:.c=.o)
OBJS_F	= _objFiles/


all: $(NAME)

$(NAME): 

			@echo $(CURSIVE)$(GRAY) "     - Creating object directory..." 
					@mkdir -p $(OBJS_F)
					@echo "     - Making object files..." 
					@gcc $(CFLAGS) -c $(addprefix $(SRC_DIR), $(SRC_FILES))
					@echo "     - Moving object files to $(OBJS_F)..." 	
					@mv $(OBJS) $(OBJS_F)
					@echo "     - Compiling Libft..." 
					@make -C $(LIBF_DIR)
					@echo "     - Compiling $(NAME)..." 
					@gcc $(FLAGS) $(addprefix $(OBJS_F), $(OBJS)) $(LIBFT) -o $(NAME)
					@echo "- Pipex Compiled -"

clean:
					@make clean -C ./libft
					@rm -rf $(OBJS_F)
					@rm -f ${OBJS_F} ${OBJ_FILES}

fclean: 	clean
					@make -C $(LIBF_DIR) fclean
					@rm -f $(NAME)

re:			fclean all