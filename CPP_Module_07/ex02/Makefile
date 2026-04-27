NAME     = Array
CXX      = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror

# Solo archivos que generan código real (.cpp)
SRC      = main.cpp
OBJ      = $(SRC:.cpp=.o)

# Es buena práctica listar los headers como dependencias 
# para que si cambias el .hpp, el Makefile sepa que debe recompilar.
DEPS     = Array.hpp Array.tpp

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

# Aquí decimos que el .o depende del .cpp Y de los headers
%.o: %.cpp $(DEPS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re