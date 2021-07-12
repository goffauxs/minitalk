# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/12 12:15:45 by sgoffaux          #+#    #+#              #
#    Updated: 2021/07/12 13:34:06 by sgoffaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT		= client
SERVER		= server
NAME		= $(CLIENT) $(SERVER)
LIBFT_A		= libft.a
LIBFT_DIR	= libft/
LIBFT		= $(addprefix $(LIBFT_DIR), $(LIBFT_A))

CC		= gcc
INCLUDE	= includes
CFLAGS	= -Wall -Wextra -Werror -I$(INCLUDE)
RM		= rm -rf

CLIENT_S = $(CLIENT).c
SERVER_S = $(SERVER).c

CLIENT_O = $(CLIENT_S:%.c=%.o)
SERVER_O = $(SERVER_S:%.c=%.o)

all:		$(NAME)

bonus: 		all

$(CLIENT):	$(LIBFT) $(CLIENT_O)
			@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(CLIENT_O) -o client
			@echo "Linked into executable \033[0;32mclient\033[0m."

$(SERVER):	$(LIBFT) $(SERVER_O)
			@$(CC) $(CFLAGS) -L$(LIBFT_DIR) -lft $(SERVER_O) -o server
			@echo "Linked into executable \033[0;32mserver\033[0m."

$(LIBFT):
			@$(MAKE) -s -C $(LIBFT_DIR)
			@echo "Compiled libft."

.c.o:
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)
			@echo "Compiling $<."

clean:
			@$(RM) $(CLIENT_O) $(SERVER_O)
			@echo "Removed object files."
			@$(MAKE) clean -s -C $(LIBFT_DIR)
			@echo "Clean libft."

fclean: 	clean
			@$(MAKE) fclean -s -C $(LIBFT_DIR)
			@echo "Full clean libft."
			@$(RM) $(NAME)
			@echo "Removed executables."

re:			fclean all

.PHONY:		all clean fclean re