# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: toliver <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/20 19:50:33 by toliver           #+#    #+#              #
#    Updated: 2022/03/24 14:34:24 by toliver          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo


LIBS = ./libs/libft/libft.a \
	   ./libs/ft_printf/libftprintf.a \

INCLUDES = -I ./includes/ -I ./libs/libft/includes/ -I ./libs/ft_printf/includes/

FLAGS = -Wall -Wextra -Werror -fsanitize=address -g3

OBJS = $(addprefix objs/, $(addsuffix .o, \
		$(addprefix core/, \
			main \
			env \
			dump \
			) \
		$(addprefix utils/, \
			utils \
			) \
)) 

CC = clang

HEADERS = ./includes/philo.h 

all: $(NAME)

$(NAME): libs objs $(OBJS) $(HEADERS)
	@printf "\033[92m\033[1:32mCompiling -------------> \033[91m$(NAME)\033[0m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@make -C ./libs/libft
	@make -C ./libs/ft_printf
	@$(CC) -o $(NAME) $(INCLUDES) $(OBJS) $(FLAGS) $(LIBS) 
	
objs/%.o: srcs/%.c
	@printf  "\033[1:92mCompiling $(NAME)\033[0m %-31s\033[32m[$<]\033[0m\n" ""
	@$(CC) -o $@ -c $< $(INCLUDES) $(FLAGS)
	@printf "\033[A\033[2K"

objs:
	@mkdir -p objs/core
	@mkdir -p objs/utils

clean:
#	@	make -C ./libs/libft clean
#	@	make -C ./libs/ft_printf clean
	@printf  "\033[1:32mCleaning object files -> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@rm -rf objs

fclean: clean
	@printf  "\033[1:32mCleaning binary -------> \033[91m$(NAME)\033[0m\033[1:32m:\033[0m%-16s\033[32m[✔]\033[0m\n"
	@	rm -f $(NAME)
	@	rm -f $(MLX)
#	@	make -C ./libs/libft fclean
#	@	make -C ./libs/ft_printf fclean

re:
	@$(MAKE) fclean
	@$(MAKE)
