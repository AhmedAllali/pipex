# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahallali <ahallali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/15 23:18:10 by ahallali          #+#    #+#              #
#    Updated: 2023/01/05 10:41:21 by ahallali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
OBJS = $(SRCS:=.o)



SRCS =	ft_strlen \
		ft_strlcpy\
		ft_strlcat\
		ft_strncmp\
		ft_substr\
		ft_strjoin\
		ft_split\
		ft_putstr_fd
		
all : ${NAME} libft.h

${NAME} : ${OBJS}
	${AR} ${NAME} $^

%.o : %.c 
	${CC} ${CFLAGS} -c $< -o  $@

clean :
	${RM} ${OBJS} 

fclean : clean
	${RM} ${NAME}

re : fclean all 

.PHONY : fclean clean re
