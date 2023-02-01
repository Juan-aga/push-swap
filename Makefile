# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: juan-aga <juan_aga@student.42malaga.c      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/17 11:31:42 by juan-aga          #+#    #+#              #
#    Updated: 2023/02/01 15:46:35 by juan-aga         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= push_swap

CHECKER		:= checker

LIBFT		:= ./libft

HEADERS		:= -I ${LIBFT}/include -I ./include

LIBS		:= ${LIBFT}/libft.a

CC			:= gcc ${CFLAGS}

RM			:= rm -f

CFLAGS		:= -Wall -Wextra -Werror

ifdef DEBUG
	CFLAGS += -g
	MAKE += DEBUG=1
endif

#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

SRC_DIR		:= ./src

SRC_PS_FILE	:= ft_check_args.c		\
			   ft_error.c			\
			   ft_init_stack.c		\
			   ft_stack.c			\
			   ft_utils.c			\
			   ft_swap_and_push.c	\
			   ft_rotate.c			\
			   ft_order.c			\
			   ft_dest.c

SRC_PS		:= $(addprefix ${SRC_DIR}/push_swap/,${SRC_PS_FILE})

OBJ_PS		:= ${SRC_PS:.c=.o}

SRC_CK_FILE	:= checker.c

SRC_CK		:= $(addprefix ${SRC_DIR}/checker/,${SRC_CK_FILE})

OBJ_CK		:= ${SRC_CK:.c=.o} \
			   ${OBJ_PS}

%.o:%.c
			@${CC} -o $@ -c $< ${HEADERS} && printf "${CGREEN}Compiling: ${CYELLOW}$(notdir $<\n)"

all:		${LIBS} ${NAME}

${LIBS}:
			git submodule update --init
			@${MAKE} -C ${LIBFT}

${NAME}:	${OBJ_PS} ${SRC_DIR}/push_swap/push_swap.c
			@echo "\n${CGREEN}${NAME} objects files were created\n"
			@${CC} ${OBJ_PS} ${LIBS} ${HEADERS} ${SRC_DIR}/push_swap/push_swap.c -o ${NAME}
			@echo "${NAME} was compiled.\n"
			@echo "Compiled with flags: ${CFLAGS}\n${CRESET}"

${CHECKER}:	${LIBS} ${OBJ_CK}
			@echo "\n${CGREEN}${CHECKER} objects files were created\n"
			@${CC} ${OBJ_CK} ${LIBS} ${HEADERS} -o ${CHECKER} 
			@echo "${CHECKER} was compiled.\n"
			@echo "Compiled with flags: ${CFLAGS}\n${CRESET}"

clean:		
			@${RM} ${OBJ_PS} ${OBJ_CK}
			@echo "${CRED}${NAME} objects files were deleted${CRESET}"
			@${MAKE} -C ${LIBFT} clean

fclean:	
			@${RM}$  ${OBJ_PS} ${OBJ_CK}
			@echo "${CRED}${NAME} objects files were deleted${CRESET}"
			@${RM} ${NAME} ${CHECKER}
			@echo "${CRED}${NAME} was deleted${CRESET}"
			@${MAKE} -C ${LIBFT} fclean
			
re:			fclean all

.PHONY:		re clean fclean all
