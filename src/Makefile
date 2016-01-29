NAME:=			MonkGenocide
SRCDIR:=		source
SRC:=			$(SRCDIR)/Character.cpp	\
			$(SRCDIR)/Player.cpp
OBJ:=			$(SRC:.cpp=.o)

CXX:=			g++
CXXFLAGS:=		-I include -W -Wall -Wextra -Werror
LDFLAGS:=		
LDLIBS:=

all:			$(NAME)

$(NAME):		$(OBJ)
			$(CXX) -o $@ $^ $(CXXFLAGS) $(LDFLAGS) $(LDLIBS)
			@echo === BUID COMPLETE ===

clean:
			@rm -fv $(OBJ)

fclean:			clean
			@rm -fv $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
