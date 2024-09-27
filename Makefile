# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rgramati <rgramati@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/05 17:09:56 by rgramati          #+#    #+#              #
#    Updated: 2024/09/27 01:58:48 by rgramati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


#
# Vars
#

LIBNAME		=	ft_chunk.a

SRC_DIR		:=	src

OBJ_DIR		:=	build

SRCS		:=	ft_chunk.c	\
				utils.c		\
				accessors.c

SRCS		:=	$(addprefix $(SRC_DIR)/, $(SRCS))

OBJS 		:=	$(addprefix $(OBJ_DIR)/, $(SRCS:%.c=%.o))

INCLUDES	:=	include

CC			:=	gcc

CFLAGS		:=	-Wall -Wextra -Werror -g3

COPTS		:=	-I ./$(INCLUDES)

RM			:=	rm -rf

TEST		:=	ft_chunk_test

#
# Rules
#

all:	$(LIBNAME)

$(LIBNAME): $(OBJS)
	@ar rc $@ $^
	@echo " $(GREEN)$(BOLD)$(ITALIC)■$(RESET)  building	$(GRAY)$(BOLD)$(ITALIC)$(LIBNAME)$(RESET)"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(@D)
	@echo " $(CYAN)$(BOLD)$(ITALIC)■$(RESET)  compiling	$(GRAY)$(BOLD)$(ITALIC)$(shell echo $@ | rev | cut -d '/' -f 1 | rev)$(RESET) from $(GRAY)$(BOLD)$(ITALIC)$(shell echo $^ | rev | cut -d '/' -f 1 | rev)$(RESET)"
	@$(CC) $(CFLAGS) $(COPTS) -o $@ -c $^

test:
	$(CC) $(CFLAGS) $(COPTS) $(TEST).c $(LIBNAME) -o $(TEST)

clean:
	echo " $(RED)$(BOLD)$(ITALIC)■$(RESET)  deleted	$(GRAY)$(BOLD)$(ITALIC)$(OBJS)$(RESET)"
	$(RM) $(OBJS)
	$(RM) $(OBJ_DIR)
	$(RM) $(TEST)

fclean:		clean
	echo " $(RED)$(BOLD)$(ITALIC)■$(RESET)  deleted	$(GRAY)$(BOLD)$(ITALIC)$(LIBNAME)$(RESET)"
	$(RM) $(LIBNAME)

re:			fclean all

.PHONY:		all clean fclean test re
.SILENT:	all clean fclean test re

#
# COLORS
# 

BOLD			=	\033[1m
ITALIC			=	\033[3m

BLACK			=	\033[30m
RED				=	\033[31m
GREEN			=	\033[32m
YELLOW			=	\033[33m
BLUE			=	\033[34m
MAGENTA			=	\033[35m
CYAN			=	\033[36m
WHITE			=	\033[37m
GRAY			=	\033[90m

RESET			=	\033[0m

LINE_CLR		=	\33[2K\r
