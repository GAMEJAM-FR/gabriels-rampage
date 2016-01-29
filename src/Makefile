NAME:=			MonkGenocide
SRCDIR:=		source
SRC:=			$(SRCDIR)/main.cpp \
			$(SRCDIR)/Character.cpp
OBJ:=			$(SRC:.cpp=.o)

CXX:=			g++
CXXFLAGS:=		-W -Wall -Wextra -Werror
LDFLAGS:=		-I include
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
