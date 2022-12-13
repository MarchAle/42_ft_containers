# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvallien <dvallien@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/04 16:27:56 by dvallien          #+#    #+#              #
#    Updated: 2022/10/21 11:11:17 by dvallien         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = containers
CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

PATH_SRCS		=	srcs
PATH_DEP		=	dep
PATH_OBJS		=	obj
PATH_INCLUDES	=	incs

LST_SRCS		=	main.cpp 				\


LST_OBJS		=	${LST_SRCS:.cpp=.o}
LST_DEP			=	${LST_SRCS:.cpp=.d}

SUB_DIR			= 	vector	\
					map		\

SRC =		$(addprefix ${PATH_SRCS}/,${LST_SRCS})
DEP =		$(addprefix ${PATH_DEP}/,${LST_DEP})
OBJS =		$(addprefix ${PATH_OBJS}/,${LST_OBJS})

all :				${NAME} Makefile

${NAME} :			${OBJS}
					${CC} ${FLAGS} ${OBJS} -o $@

${PATH_DEP}/%.d :	${PATH_SRCS}/%.cpp Makefile
					mkdir -p $(PATH_DEP) $(addprefix $(PATH_DEP)/, $(SUB_DIR))
					${CC} ${FLAGS} -MM -MF $@ -MT "${PATH_OBJS}/$*.o $@" $<

${PATH_OBJS}/%.o:	${PATH_SRCS}/%.cpp Makefile
					mkdir -p $(PATH_OBJS) $(addprefix $(PATH_OBJS)/, $(SUB_DIR))
					${CC} ${FLAGS} -c $< -o $@ -I ${PATH_INCLUDES}

clean :
					rm -rf obj dep

fclean :			clean bclean
					rm -f ${NAME}

re :				fclean all

-include ${DEP}

.PHONY: all re clean fclean