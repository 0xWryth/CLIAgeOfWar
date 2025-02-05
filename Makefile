CXX=g++ -g
CXXFLAGS=-Wall -Wextra -Werror
NAME=main
SRC_DIR=./src/
OUT_DIR=./out/
OBJ_DIR=./obj/
# Please include bellow every generated .o files
O=$(OBJ_DIR)Archer.o $(OBJ_DIR)Catapult.o $(OBJ_DIR)Console.o $(OBJ_DIR)Fantassin.o $(OBJ_DIR)Game.o $(OBJ_DIR)Grid.o $(OBJ_DIR)GridCase.o $(OBJ_DIR)Health.o $(OBJ_DIR)HomeCase.o $(OBJ_DIR)main.o $(OBJ_DIR)Panel.o $(OBJ_DIR)Player.o $(OBJ_DIR)SuperSoldier.o $(OBJ_DIR)Troup.o

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
