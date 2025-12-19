CX = c++
CXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = AMateria.cpp Ice.cpp Cure.cpp Character.cpp MateriaSource.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

NAME = materia

all: $(NAME)

$(NAME): $(OBJS)
	$(CX) $(CXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CX) $(CXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
