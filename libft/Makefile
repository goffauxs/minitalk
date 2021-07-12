# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgoffaux <sgoffaux@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/05 12:04:24 by sgoffaux          #+#    #+#              #
#    Updated: 2021/07/12 14:04:06 by sgoffaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_atoi.c \
			ft_itoa.c \
			ft_isdigit.c \
			ft_strlen.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putchar_fd.c

OBJS	=	$(SRCS:%.c=%.o)

BOBJS	=	$(BONUS:%.c=%.o)

CC		=	gcc

INCLUDE =	includes

CFLAGS	=	-Wall -Wextra -Werror -I$(INCLUDE) -c

RM		=	rm -f

NAME	=	libft.a

all:		$(NAME)

$(NAME):	$(OBJS)
			ar rc $(NAME) $(OBJS)

.c.o:
			$(CC) $(CFLAGS) $< -o ${<:.c=.o}

clean:
			$(RM) $(OBJS) $(BOBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
