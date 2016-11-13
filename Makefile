# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/11/13 16:49:11 by rabougue         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################_COLOR_#####################################
GREEN = \033[38;5;10m
GREY = \033[38;5;60m
RED = \033[38;5;9m
END = \033[0m
##################################_COMPILATION_#################################
NAME = lem-in
CC = gcc
FLAG = -Wall -Wextra -Werror
LFT = ./libft/libft.a
SRCS = ./source/main.c ./source/parsing.c ./source/linked_list.c ./source/map.c
INCLUDE = -I ./include/ -I ./libft/includes/

OBJS = $(SRCS:.c=.o)

###########################_RELINK_MODIFY_.h####################################
RELINK_H = ./include/common.h
################################################################################

###################################Compilation##################################
all: $(NAME)

$(NAME): $(OBJS)
	@make -s -C ./libft/
	@$(CC) $(LFT) $(OBJS) -o $(NAME)
	@printf "✅  Compilation done.\n"

%.o : %.c $(RELINK_H) ./Makefile
	@printf "                                                               \r"
	@printf "✅  $(notdir $<)\r"
	@$(CC) -c $(FLAG) $< $(INCLUDE) -o $@

clean:
	@printf "                                                               \r"
	@printf "✅  all .o deleted\n"
	@rm -f $(OBJS)
	@make -s clean -C ./libft/

fclean:
	@printf "                                                               \r"
	@printf "✅  libft.a, all .o and rabougue.filler deleted\n"
	@rm -f $(NAME) $(CHECKER) $(OBJS) $(OBJS_CHECKER)
	@make -s fclean -C ./libft/

re: fclean all
