# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alcierra <alcierra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 19:48:32 by alcierra          #+#    #+#              #
#    Updated: 2022/03/27 11:28:39 by alcierra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_B	=	checker
HEADER	=	ft_push_swap.h
SRCS	=	ft_strs_to_ints.c					\
			ft_operation_swap.c					\
			ft_create_data_element.c	ft_sort.c					\
			ft_operation_push.c										\
			ft_stack_free.c				ft_operation_rotate.c		\
			ft_operation_revrotate.c					\
			ft_sort_ints.c											\
			ft_data.c					ft_convert.c				\
			ft_smth.c					ft_create_stacks.c			\
			ft_dlst_mindata.c			ft_is_sorted.c				\
			ft_sort_manager.c							\
			ft_stack_a_middle.c			ft_3_sort.c					\
			ft_3_sort_cases.c			ft_check_coincedence.c		\
			ft_create_dlist.c							\
			ft_strint_to_norm.c										\
			ft_sort_butterfly.c			ft_sort_butterfly_simple.c	\
			ft_dlstdata_max.c			ft_push_a_max_b.c

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

FROM	=	-200
TO		=	200

all: lib $(FLDR_O) $(NAME)

bonus: lib $(NAME_B)

lib:
		${I_MAKE} bonus
		${I_MAKE}

$(FLDR_O):
		mkdir $(FLDR_O)
		mkdir $(FLDR_O)bonus

$(NAME): ${OBJS_WD} ${FLDR_O}main.o ${HEADER}
		gcc $(OBJS_WD) ${FLDR_O}main.o -o $(NAME) -I. $(INCLUDE)

$(NAME_B): $(FLDR_O) ${OBJS_WD} ${OBJS_B_WD}
		gcc $(OBJS_WD) $(OBJS_B_WD) -o $(NAME_B) -I. $(INCLUDE)

clean:
		rm -rf $(FLDR_O)main.o ${OBJS_WD} ${OBJS_B_WD}
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

leaks:
		leaks -atExit -- ./push_swap 65 545 5 98 64 84

gen:
		@ruby -e "puts ($(FROM)..$(TO)).to_a.shuffle.join(' ')"

.PHONY: all clean fclean re bonus
