##
## Makefile for Makfile in /home/riamon_v/rendu/CPP/cpp_arcade/src_liblapin
##
## Made by Riamon Vincent
## Login   <riamon_v@epitech.net>
##
## Started on  Thu Apr  6 18:10:28 2017 Riamon Vincent
## Last update Mon Apr 10 21:49:00 2017 Riamon Vincent
##

NAME:=		../../lib/lib_arcade_sfml.so
SRCDIR:=	src/

INCLUDE:=	../../include\

SRC:=		sfml.cpp \

CXX:=		g++
CXXFLAGS:=	-W -Wall -Wextra -fpic -g -std=c++14 -lsfml-audio \
						-lsfml-graphics -ldl \
						-lsfml-window \
						-lsfml-system

LDFLAGS:=	-shared

SRC:=		$(addprefix $(SRCDIR), $(SRC))
OBJ:=		$(SRC:.cpp=.o)
RM:=		rm -f

DEFAULT:=	"\033[00;0m"
GREEN:=		"\033[0;32;1m"
RED:=		"\033[0;31;1m"
CYAN:=		"\033[0;36;1m"

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS) &&\
	echo -e $(GREEN)"[LIB]"$(CYAN) $(NAME)$(DEFAULT) || \
	echo -e $(RED)"[XX]"$(DEFAULT) $(NAME)
	for file in $(SRC); do fgrep -niH -e TODO -e FIXME $$file --color=auto; done; true

clean:
	echo -e $(CYAN)"Cleaning $(NAME) tmp files..." $(DEFAULT)
	$(RM) $(OBJ)

fclean:	clean
	echo -e $(CYAN)"Cleaning $(NAME) executable..." $(DEFAULT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re

.cpp.o:
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(foreach dir, $(INCLUDE), -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<
