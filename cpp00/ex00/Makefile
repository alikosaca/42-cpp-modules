NAME = ./megaphone

CPP = c++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98

SRC = Megaphone.cpp 
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

%.o: %.cpp
# 	@echo "----------------------------------------"
# 	@echo "input: " $<
# 	@echo "output: " $@
# 	@echo "----------------------------------------"
	$(CPP) $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CPP) $(CPPFLAGS) $(OBJ) -o $(NAME)


clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean
