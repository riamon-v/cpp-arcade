##
## Makefile :D
##
## Made by David Zeng
## Login   <zeng_d@epitech.net>
##
## Started on  Mon Oct 12 13:31:18 2015 David Zeng
## Last update Fri Apr  7 10:52:28 2017 Riamon Vincent
##

NAME:=		arcade
SRCDIR:=	src/
INCLUDE:=	include/ \

SRC:=		main.cpp \

CXX:=		g++
CXXFLAGS:=	-W -Wall -Wextra -g -std=c++14 -ldl
SRC:=		$(addprefix $(SRCDIR), $(SRC))
OBJ:=		$(SRC:.cpp=.o)
RM:=		rm -f

DEFAULT:=	"\033[00;0m"
GREEN:=		"\033[0;32;1m"
RED:=		"\033[0;31;1m"
CYAN:=		"\033[0;36;1m"

all: $(NAME)

$(NAME): $(OBJ)
	make -C ./src_liblapin/
	make -C ./src_ncurses/
	make -C ./src_sfml/
	$(CXX) -o $(NAME) $(OBJ) $(CXXFLAGS) $(LDFLAGS) && \
		echo -e $(GREEN)"[BIN]"$(CYAN) $(NAME)$(DEFAULT) || \
		echo -e $(RED)"[XX]"$(DEFAULT) $(NAME)
	for file in $(SRC); do fgrep -niH -e TODO -e FIXME $$file --color=auto; done; true

clean:
	make clean -C ./src_liblapin/
	make clean -C ./src_ncurses/
	make clean -C ./src_sfml/
	echo -e $(CYAN)"Cleaning $(NAME) tmp files..." $(DEFAULT)
	$(RM) $(OBJ)

fclean:	clean
	make fclean -C ./src_liblapin/
	make fclean -C ./src_ncurses/
	make fclean -C ./src_sfml/
	echo -e $(CYAN)"Cleaning $(NAME) executable..." $(DEFAULT)
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

.SILENT: all $(NAME) clean fclean re

.cpp.o:
	@$(CXX) -c $< -o $@ $(CXXFLAGS) $(foreach dir, $(INCLUDE), -I$(dir)) && \
		echo -e $(GREEN)"[OK]"$(DEFAULT) $< || \
		echo -e $(RED)"[KO]"$(DEFAULT) $<
