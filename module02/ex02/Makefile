CX = c++
CXFLAGS = -Wall -Wextra -Werror -std=c++98 -g3

SRCS = main.cpp Fixed.cpp

OBJS = $(SRCS:.cpp=.o)
NAME = Fixed

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
