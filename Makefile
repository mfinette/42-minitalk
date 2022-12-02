# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfinette <mfinette@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 10:33:27 by mfinette          #+#    #+#              #
#    Updated: 2022/12/01 21:30:50 by mfinette         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SHELL = /bin/sh
HEADER = include/minitalk.h
CFLAGS += -Iinclude -Wall -Werror -Wextra
RM		= @rm -f
DEF_COLOR = \033[0;39m
YELLOW = \033[0;93m
GREEN = \033[0;92m
BLUE = \033[0;94m
CYAN = \033[0;96m

NAME_SERVER = server
NAME_CLIENT = client

SRC_COMMON = src/utils

SRCS_CLIENT:= 		src/client/client.c				\
					src/client/parse_args.c			\
					src/client/send_message.c		\
					src/utils/ft_isdigit.c			\
					src/utils/ft_atoi.c				\
					src/utils/binary_tools.c		\
					src/utils/ft_putendl_fd.c		\
					src/utils/ft_putstr_fd.c		\
					src/utils/ft_putchar_fd.c		\
					
								

SRCS_SERVER:=		src/server/display_pid.c		\
					src/server/server.c				\
					src/utils/ft_putchar_fd.c		\
					src/utils/ft_itoa.c				\
					src/utils/ft_putendl_fd.c		\
					src/utils/ft_calloc.c			\
					src/utils/ft_bzero.c			\
					src/utils/ft_strlen.c			\
					src/utils/ft_putstr_fd.c		\
					
OBJS_SERVER = $(SRCS_SERVER:.c=.o)

OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_SERVER): $(OBJS_SERVER)
	@echo "$(GREEN)😳😎server compiled!😎😳$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME_SERVER) $(OBJS_SERVER)

$(NAME_CLIENT): $(OBJS_CLIENT)
	@echo "$(GREEN)😳😎client compiled!😎😳$(DEF_COLOR)"
	@$(CC) $(CFLAGS) -o $(NAME_CLIENT) $(OBJS_CLIENT)

%.o:%.c Makefile $(HEADER)
	@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"	
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS_CLIENT) $(OBJS_SERVER)
	@echo "$(CYAN)pushswap object files cleaned!$(DEF_COLOR)"

fclean: clean
	@$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	@echo "$(CYAN)3$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)2$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(CYAN)1$(DEF_COLOR)"
	@sleep 0.2
	@echo "$(GREEN)pushswap executable files cleaned!$(DEF_COLOR)"
re: clean all

debug: CFLAGS += -g
debug: fclean 

.PHONY: all clean fclean re  debug
