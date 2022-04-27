#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiglesia <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/09 12:55:34 by jiglesia          #+#    #+#              #
#    Updated: 2022/04/27 21:40:49 by jiglesia         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME		=	ft_containers
CHNAME		=	std_containers

#****************** INC *******************#
# General
INC			=	./includes/

# Libft
SUB_MAKE	=
INCFT		=

INCLUDE		=	-I $(INC)

INC_LIB		=


#***************** SRC* *******************#

DIRSRCS		=	./srcs/
DIRCHEC		=
DIRMV		=
DIRINPUT	=
DIRLIST		=
DIREVENT	=
DIRLASER	=

SRCS		=	main.cpp
CHECKER		=
MOVES		=
INPUT		=
LIST		=
EVENTS		=
LOADING		=

FTSRC		=	$(SRCS)
STDSRC		=	$(SRCS)

#***************** DEPS ******************#

DIROBJ		=	./depo/

OAUX		=	$(FTSRC:%=$(DIROBJ)%)
DEPS		=	$(OAUX:.cpp=.d)
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

#************************ DEPS COMPILATION *************************

%.o		:		../$(DIRSRCS)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRCHEC)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRMV)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRINPUT)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRLIST)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIREVENT)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

%.o		:		../$(DIRLASER)/%.cpp
				$(CC) $(CFLAGS) $(INCLUDE) -MMD -o $@ -c $<

#************************ MAIN COMPILATION *************************

$(NAME)	:		$(OBJS)
				$(CC)  $(INCLUDE) $(CFLAGS) -o $(NAME) $(OBJS) $(INC_LIB)
				@$(ECHO) '> Compiled'

checker	:		$(COBJS)
				$(CC)  $(INCLUDE) $(CFLAGS) -o $(CHNAME) $(COBJS) $(INC_LIB)
				@$(ECHO) '> Compiled'

clean	:
				@($(RM) $(OBJS))
				@($(RM) $(COBJS))
				@($(RM) $(DEPS))
				@($(RM) $(CDEPS))
				@$(ECHO) '> Directory cleaned'

all		:		$(NAME)

fclean	:		clean
				@$(RM) $(NAME)
				@$(RM) $(CHNAME)
				@$(ECHO) '> Remove executable'

re		:		fclean all

.PHONY	:		all clean re

-include $(DEPS)
