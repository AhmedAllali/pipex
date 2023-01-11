# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/03 17:43:09 by ahallali          #+#    #+#              #
#    Updated: 2023/01/05 10:56:30 by ahallali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = pipex
LIBFT = libft/libft.a
CFLAGS = -Wall -Wextra -Werror
RM = rm -f
OBJS = $(SRCS:.c=.o)

SRCS = pipex.c \
	   pipex_utils.c \
	
		
all : ${NAME}  pipex.h

${NAME} : $(LIBFT) ${OBJS}
	 cc $(CFLAGS) -o $(NAME) $^


%.o: %.c  pipex.h 
	${CC} ${CFLAGS} -c $< -o $@
	
$(LIBFT):
	make -C libft && make clean


clean :
	${RM} ${OBJS}
	make clean -C libft

fclean : clean
	${RM} ${NAME}
	make fclean -C libft

re : fclean all 

.PHONY : fclean clean re all