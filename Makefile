# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 11:41:35 by ancoulon          #+#    #+#              #
#    Updated: 2020/02/11 16:50:34 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBDIR		= ./libft

LIB			= libft.a

INCDIR		= ./includes

SRCDIR		= ./sources

SRCS		= ft_parse_utils.c ft_parse.c ft_printf.c

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= ar rcs

RM			= rm -f

MAKE		= make

.c.o:
			$(CC) $(CFLAGS) -I$(INCDIR) -c $^ -o $@

$(NAME):	$(OBJS)
			$(MAKE) -C $(LIBDIR)
			$(AR) $(NAME) $(LIBDIR)/$(LIB) $(OBJS)
			ranlib $(NAME)

all:		$(NAME)

clean:
			$(MAKE) -C $(LIBDIR) clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) -C $(LIBDIR) fclean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re