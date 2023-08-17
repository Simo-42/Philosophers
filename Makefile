# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhajji-b <mhajji-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/22 16:41:13 by mhajji-b          #+#    #+#              #
#    Updated: 2023/08/14 13:35:02 by mhajji-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = ./srcs

SRCS	= main.c ft_atoi.c init.c parsing.c routine.c mutex_init.c ft_action.c check_create.c one_philo.c printing.c


OBJS			=	$(addprefix $(SRC_DIR)/, $(SRCS:%.c=%.o))

NAME			=	philo

CC				=	cc 

CC2				=	cc -pthread -fsanitize=thread -g3

CC1				=	cc -pthread -fsanitize=thread

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	$(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:		${NAME}

ff :	$(OBJS)
	$(CC1) -o $(NAME) $(OBJS)

g3 :	$(OBJS)
	$(CC2) -o $(NAME) $(OBJS)

clean:
	${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}

re:			fclean all

.PHONY: 	all clean fclean re