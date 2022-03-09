# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:48:32 by alcierra          #+#    #+#              #
#    Updated: 2022/03/09 13:50:43 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
HEADER	=	ft_push_swap.h
SRCS	=	ft_strs_to_ints.c			ft_list_operations.c		\
			ft_operation_swap.c			ft_construct_stack.c		\
			ft_create_data_element.c	ft_sort.c					\
			ft_operation_push.c			ft_arg_checker.c			\
			ft_stack_free.c				ft_operation_rotate.c		\
			ft_operation_revrotate.c

SRCS_B	=	bonus/main.c				bonus/ft_process_input.c	\
			bonus/get_next_line.c		bonus/get_next_line_utils.c

OBJS	=	${SRCS:.c=.o}
OBJS_B	=	${SRCS_B:.c=.o}

FLDR_S	=	srcs/
FLDR_O	=	objs/

SRCS_WD	=	$(addprefix ${FLDR_S},${SRCS})
OBJS_WD	=	$(addprefix ${FLDR_O},${OBJS})
SRCS_B_WD	=	$(addprefix ${FLDR_S},${SRCS_B})
OBJS_B_WD	=	$(addprefix ${FLDR_O},${OBJS_B})

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
		mkdir $(FLDR_O)bonus

$(NAME): ${OBJS_WD} ${FLDR_O}main.o ${HEADER}
		gcc -I. $(INCLUDE) $(OBJS_WD) ${FLDR_O}main.o -o $(NAME)

bonus:	$(FLDR_O) ${OBJS_WD} ${OBJS_B_WD}
		gcc -I. $(INCLUDE) $(OBJS_WD) $(OBJS_B_WD) -o checker

clean:
		rm -rf ${OBJS_WD} ${OBJS_B_WD}
		${I_MAKE} clean

fclean: clean
		rm -rf ${NAME} checker
		${I_MAKE} fclean

${FLDR_O}%.o : ${FLDR_S}%.c ${HEADER}
		gcc ${FLAGS} -c $< -o $@

re: fclean all

norm:
		norminette ft_push_swap.h
		norminette -R CheckForbiddenSourceHeader $(FLDR_S)*.c $(FLDR_S)bonus/*.c

.PHONY: all clean fclean re
