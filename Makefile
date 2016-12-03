# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rabougue <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/12/10 19:16:51 by rabougue          #+#    #+#              #
#    Updated: 2016/11/23 19:46:16 by rabougue         ###   ########.fr        #
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
SRC = ./source
SRCS = $(SRC)/main.c \
	   $(SRC)/map.c \
	   $(SRC)/parsing.c \
	   $(SRC)/parsing_ants.c \
	   $(SRC)/parsing_room.c \
	   $(SRC)/parsing_command.c \
	   $(SRC)/parsing_comment.c \
	   $(SRC)/parsing_link.c \
	   $(SRC)/error.c \
	   $(SRC)/algo.c \
	   $(SRC)/print_ants.c \

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
	@printf "\n✅  Compilation done.\n"

%.o : %.c $(RELINK_H) ./Makefile
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

norme:
	norminette ./include/common.h ./libft/*.c ./libft/includes/*.h ./source/*.c \
		./libft/ft_fprintf/includes/ft_fprintf.h ./libft/ft_fprintf/sources/*.c
