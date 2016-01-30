NAME:=			MonkGenocide
SRCDIR:=		source
SRC:=			$(SRCDIR)/main.cpp \
			$(SRCDIR)/GameWindow.cpp \
			$(SRCDIR)/Asset.cpp \
			$(SRCDIR)/Character.cpp
OBJ:=			$(SRC:.cpp=.o)

CXX:=			g++
CXXFLAGS:=		-I include -W -Wall -Wextra -Werror
LDFLAGS:=		-L /usr/lib/
LDLIBS:=		-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

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
