# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ancoulon <ancoulon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/04 11:41:35 by ancoulon          #+#    #+#              #
#    Updated: 2020/02/25 10:25:21 by ancoulon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

LIBDIR		= ./libft

LIB			= libft.a

INCDIR		= ./includes

SRCDIR		= ./sources

SRCS		= ft_printf.c ft_process.c ft_parse.c ft_parse_utils.c            \
			  ft_print_c.c ft_print_s.c ft_print_p.c ft_print_d.c             \
			  ft_print_u.c ft_print_x.c ft_print_ux.c ft_print_pct.c

OBJS		= $(addprefix $(SRCDIR)/, $(SRCS:.c=.o))

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

AR			= libtool -static -o

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
