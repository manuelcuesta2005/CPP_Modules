NAME = FragTrap

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

SRC = ClapTrap.cpp \
	  ScavTrap.cpp \
	  FragTrap.cpp \
      main.cpp 

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)
	
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@ 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re