##
## Makefile for Makfile in /home/riamon_v/rendu/CPP/cpp_arcade/src_liblapin
##
## Made by Riamon Vincent
## Login   <riamon_v@epitech.net>
##
## Started on  Thu Apr  6 18:10:28 2017 Riamon Vincent
## Last update Fri Apr 14 00:54:42 2017 Riamon Vincent
##

NAME:=		../../games/lib_arcade_snake.so
NAME1:=		../../games/lib_arcade_nibbler.so
NAME2:=		../../games/lib_arcade_blockade.so

SRCDIR:=	src/

INCLUDE:=	../../include \

SRC:=		main.cpp \
		Map.cpp \
		Snake.cpp \
		../../Errors.cpp

CXX:=		g++
CXXFLAGS:=	-W -Wall -Wextra -fpic -g -std=c++14 \

LDFLAGS:=	-shared
SRC:=		$(addprefix $(SRCDIR), $(SRC))
OBJ:=		$(SRC:.cpp=.o)
RM:=		rm -f

DEFAULT:=	"\033[00;0m"
GREEN:=		"\033[0;32;1m"
RED:=		"\033[0;31;1m"
CYAN:=		"\033[0;36;1m"

all: $(NAME) $(NAME1) $(NAME2)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS) &&\
	echo -e $(GREEN)"[LIB]"$(CYAN) $(NAME)$(DEFAULT) || \
	echo -e $(RED)"[XX]"$(DEFAULT) $(NAME)
	for file in $(SRC); do fgrep -niH -e TODO -e FIXME $$file --color=auto; done; true

$(NAME1): $(OBJ)
	$(CXX) -o $(NAME1) $(OBJ) $(CXXFLAGS) $(LDFLAGS) &&\
	echo -e $(GREEN)"[LIB]"$(CYAN) $(NAME1)$(DEFAULT) || \
	echo -e $(RED)"[XX]"$(DEFAULT) $(NAME1)
	for file in $(SRC); do fgrep -niH -e TODO -e FIXME $$file --color=auto; done; true

$(NAME2): $(OBJ)
	$(CXX) -o $(NAME2) $(OBJ) $(CXXFLAGS) $(LDFLAGS) &&\
	echo -e $(GREEN)"[LIB]"$(CYAN) $(NAME2)$(DEFAULT) || \
	echo -e $(RED)"[XX]"$(DEFAULT) $(NAME2)
	for file in $(SRC); do fgrep -niH -e TODO -e FIXME $$file --color=auto; done; true

clean:
	echo -e $(CYAN)"Cleaning $(NAME) tmp files..." $(DEFAULT)
	echo -e $(CYAN)"Cleaning $(NAME1) executable..." $(DEFAULT)
	echo -e $(CYAN)"Cleaning $(NAME2) executable..." $(DEFAULT)
	$(RM) $(OBJ)

fclean:	clean
	echo -e $(CYAN)"Cleaning $(NAME) executable..." $(DEFAULT)
	echo -e $(CYAN)"Cleaning $(NAME1) executable..." $(DEFAULT)
	echo -e $(CYAN)"Cleaning $(NAME2) executable..." $(DEFAULT)
	$(RM) $(NAME) $(NAME1) $(NAME2)

re: fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) $(NAME1) $(NAME2) clean fclean re

.cpp.o:
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(foreach dir, $(INCLUDE), -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<
