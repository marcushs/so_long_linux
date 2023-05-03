# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hleung <hleung@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:00:57 by hleung            #+#    #+#              #
#    Updated: 2023/05/03 13:02:07 by hleung           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

NAME			=	so_long

MLXFLAGS		=	-L mlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFTFLAGS		=	-L libft -lft

LIBS_FILES		=	$(shell find libft mlx_linux -type f)

HEADER_FILES	=	$(shell find includes -type f)

CFLAGS			=	-Wall -Werror -Wextra #-fsanitize=address

CC				=	gcc

RM				=	rm -rf

LIST_SRCS		=	flood_fill_utils.c events.c free.c \
					map_error.c map.c move.c render.c so_long.c flood_fill.c
DIR_SRCS		=	./srcs/
SRCS			=	$(addprefix ${DIR_SRCS}, ${LIST_SRCS})

LIST_OBJS		=	${LIST_SRCS:.c=.o}
DIR_OBJS		=	.objs/
OBJS			=	${addprefix ${DIR_OBJS}, ${LIST_OBJS}}

SRCS_COMPILED	= 0

HEADERS			=	includes

${DIR_OBJS}%.o:	${DIR_SRCS}%.c Makefile 
				@${CC} ${CFLAGS} -c $< -o $@ -I ${HEADERS}
			
all:		${NAME} 

${NAME}:	${DIR_OBJS} ${OBJS} ${HEADERS} ${LIBS_FILES} ${HEADER_FILES}
			@${MAKE} -sC ./libft
			@echo "${GREEN}Compiling libft...${NC}"
			@${MAKE} -sC ./mlx_linux
			@echo "${GREEN}Compiling mlx...${NC}"
			@${CC} ${CFLAGS} ${OBJS} ${LIBFTFLAGS} ${MLXFLAGS} -o ${NAME}	
			@echo "${GREEN}Compilation completed!${NC}"

${DIR_OBJS}:	
				@mkdir -p ${DIR_OBJS}
			
clean:		
			@${RM} ${DIR_OBJS}
			@${MAKE} clean -sC ./libft
			@${MAKE} clean -sC ./mlx_linux
			@echo "${YELLOW}Object files and libraries cleared!${NC}"
			
fclean:		
			@${MAKE} clean
			@${RM} ${NAME} 
			@${MAKE} fclean -sC ./libft
			@echo "${YELLOW}Executable cleared!${NC}"
			
re:			fclean 
			$(MAKE) all

.PHONY:		all clean fclean re .c.o
