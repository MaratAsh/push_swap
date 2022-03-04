# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:48:32 by alcierra          #+#    #+#              #
#    Updated: 2022/03/04 14:48:25 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	ft_push_swap.h
SRCS	=	main.c													\
			ft_strs_to_ints.c			ft_list_operations.c		\
			ft_operation_swap.c			ft_construct_stack.c		\
			ft_create_data_element.c	

OBJS	=	${SRCS:.c=.o}

FLDR_S	=	srcs/
FLDR_O	=	objs/

SRCS_WD	=	$(addprefix ${FLDR_S},${SRCS})
OBJS_WD	=	$(addprefix ${FLDR_O},${OBJS})

FLAGS	=	-Wall -Wextra -Werror

INCLUDE	=	./libft/libft.a
I_MAKE	=	make -C $(dir $(INCLUDE))

all: lib $(FLDR_O) $(NAME)

lib:
		echo $(SRCS_WD)
		${I_MAKE} bonus
		${I_MAKE}

$(FLDR_O):
		mkdir $(FLDR_O)

$(NAME): ${OBJS_WD} ${HEADER}
		gcc -I. $(INCLUDE) $(OBJS_WD) -o $(NAME)

clean:
		rm -rf ${OBJS_WD}
		${I_MAKE} clean

fclean: clean
		rm -rf ${NAME}
		${I_MAKE} fclean

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
		gcc ${FLAGS} -c $< -o $@

re: fclean all

.PHONY: all clean fclean re
