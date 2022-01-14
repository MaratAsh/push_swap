# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:48:32 by alcierra          #+#    #+#              #
#    Updated: 2022/01/14 14:23:52 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	ft_push_swap.h
SRCS	=	main.c		ft_strs_to_ints.c		

OBJS	=	${SRCS:.c=.o}
FLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	./libft/libft.a


all: lib $(NAME)

lib:
		make -C $(dir $(INCLUDE))

$(NAME): ${OBJS} ${HEADER}
		gcc -I. $(INCLUDE) $(OBJS) -o $(NAME)

clean:
		rm -rf ${OBJS} ${B_OBJS}

fclean: clean
		rm -rf ${NAME}

%.o : %.c ${HEADER}
		gcc ${FLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
