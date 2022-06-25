#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 12:55:34 by jiglesia          #+#    #+#              #
#    Updated: 2022/06/04 15:43:11 by jiglesia         ###   ########.fr        #
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
SUB_MAKE	=
INCFT		=

INCLUDE		=	-I $(INC) -I $(INCC) -I $(INCI) -I $(INCB) -I $(INCT)

INC_LIB		=


#***************** SRC* *******************#

DIRSRCS		=	./srcs/
DIRSTD		=	$(DIRSRCS)/stdtest/

SRCS		=	ft_main.cpp
STDTEST		=	std_main.cpp

FTSRC		=	$(SRCS)
STDSRC		=	$(STDTEST)

#***************** DEPS ******************#

DIROBJ		=	./depo/

OAUX		=	$(FTSRC:%=$(DIROBJ)%)
CAUX		=	$(STDSRC:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.cpp=.d)
CDEPS		=	$(CAUX:.cpp=.d)
OBJS		=	$(OAUX:.cpp=.o)
COBJS		=	$(CAUX:.cpp=.o)

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

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRSRCS)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRSTD)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		$(OBJS) $(COBJS)
				$(CC)  $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIB)
				$(CC)  $(INCLUDE) $(CFLAGS) -o $(CHNAME) $(COBJS) $(INC_LIB)
				@$(ECHO) '> Compiled'				@$(ECHO) '> Compiled'

#stdtest	:		$(COBJS)
#				$(CC)  $(INCLUDE) $(CFLAGS) -o $(CHNAME) $(COBJS) $(INC_LIB)
#				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(COBJS))
				@($(RM) $(DEPS))
				@($(RM) $(CDEPS))
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
