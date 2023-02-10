# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/18 14:56:10 by hleung            #+#    #+#              #
#    Updated: 2022/11/21 18:43:36 by hleung           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

CC		=	gcc ${CFLAGS}

RM		=	rm -f

SRCS	=	ft_printf.c ft_putadd.c ft_putchar.c ft_putnbr.c  ft_putnbr_base.c ft_putstr.c ft_putnbr_unsigned.c

OBJS	=	${SRCS:.c=.o}

HEADER	=	..

%.o:		%.c Makefile
			${CC} -c $< -o ${<:.c=.o} -I ${HEADER}

all:		${NAME}

${NAME}:	${OBJS}
			ar rcs ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		re clean fclean all .c.o


