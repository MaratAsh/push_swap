# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:48:32 by alcierra          #+#    #+#              #
#    Updated: 2022/01/14 19:33:31 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	ft_push_swap.h
SRCS	=	main.c			ft_strs_to_ints.c		ft_list_operations.c	\
			ft_operation_swap.c		

OBJS	=	${SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	./libft/libft.a
I_MAKE	=	make -C $(dir $(INCLUDE))

all: lib $(NAME)

lib:
		${I_MAKE}

$(NAME): ${OBJS} ${HEADER}
		gcc -I. $(INCLUDE) $(OBJS) -o $(NAME)

clean:
		rm -rf ${OBJS} ${B_OBJS}
		${I_MAKE} clean

fclean: clean
		rm -rf ${NAME}
		${I_MAKE} fclean

%.o : %.c ${HEADER}
		gcc ${FLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
