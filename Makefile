#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 12:55:34 by jiglesia          #+#    #+#              #
#    Updated: 2022/07/05 16:43:24 by jiglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_containers
CHNAME		=	std_containers

#****************** INC *******************#
# General
INC			=	./includes/
INCC		=	./includes/containers/
INCI		=	./includes/iterators/
INCB		=	./includes/binary_search_tree/
INCT		=	./includes/tests/

# Libft
INCLUDE		=	-I $(INC) -I $(INCC) -I $(INCI) -I $(INCB) -I $(INCT)

#***************** SRC* *******************#

DIRSRCS		=	./srcs/
DIRSTD		=	$(DIRSRCS)/stdtest/

SRCS		=	main.cpp

FTSRC		=	$(DIRSRCS)$(SRCS)

#***************** DEPS ******************#

DIROBJ		=	./depo/

OAUX		=	$(SRCS:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.hpp=.d)
OBJS		=	$(OAUX:.cpp=.o)

ifdef FLAGS
	ifeq ($(FLAGS), no)
CFLAGS		=
	endif
	ifeq ($(FLAGS), debug)
CFLAGS		=	-Wall -Wextra -Werror -ansi -pedantic -g
	endif
else
CFLAGS		=	-Wall -Wextra -Werror -std=c++98
endif

CC			=	/usr/bin/clang++
RM			=	/bin/rm -f
ECHO		=	/bin/echo -e

#************************ MAIN COMPILATION *************************

$(NAME)	:		./depo/ft_main.o ./depo/std_main.o
				$(CC)  $(INCLUDE) $(CFLAGS) -o $(NAME) ./depo/ft_main.o $(INC_LIB)
				$(CC)  $(INCLUDE) $(CFLAGS) -o $(CHNAME) ./depo/std_main.o $(INC_LIB)
				@$(ECHO) '> Compiled'				@$(ECHO) '> Compiled'

$(DIROBJ)ft_main.o	:	$(FTSRC)
					$(CC) $(CFLAGS) -DM_FT -DM_RAN=255 $(INCLUDE) -MMD -o $@ -c $<

$(DIROBJ)std_main.o	:	$(FTSRC)
						$(CC) $(CFLAGS) -DM_RAN=255 $(INCLUDE) -MMD -o $@ -c $<

clean	:
				@($(RM) $(DIROBJ)*.o)
				@($(RM) $(DIROBJ)*.d)
				@($(RM) 'ft_output' 'std_output')
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(RM) $(CHNAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

-include $(DEPS)
