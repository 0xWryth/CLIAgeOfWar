CXX=g++
CXXFLAGS=-Wall -Wextra -Werror
NAME=main
SRC_DIR=./src/
OUT_DIR=./out/
OBJ_DIR=./obj/
# Please include bellow every generated .o files
O=$(OBJ_DIR)$(NAME).o $(OBJ_DIR)Console.o

$(OBJ_DIR)%.o: $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

$(OUT_DIR)$(NAME): $(O)
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: run clean

run: $(OUT_DIR)$(NAME)
	./$<

# Clean project
clean:
	rm -f $(OBJ_DIR)*.o *~ core $(OUT_DIR)*.exe
