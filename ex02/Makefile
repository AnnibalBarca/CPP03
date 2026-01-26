CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = ClapTrap.cpp ScavTrap.cpp FragTrap.cpp main.cpp
HDRS = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp
OBJS = $(SRCS:.cpp=.o)
NAME = fragtrap

all: $(NAME)

$(NAME): $(OBJS) $(HDRS)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(OBJS:.o=.d)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
