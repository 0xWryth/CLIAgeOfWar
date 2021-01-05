CXX=g++
CXXFLAGS=-Wall -Wextra -Werror
NAME=main
SRC_DIR=./src/
OUT_DIR=./out/
OBJ_DIR=./obj/
# Please include bellow every generated .o files
O=./obj/*.o

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -c -o $@

all: Archer.o Catapult.o Console.o Fantassin.o Game.o Grid.o GridCase.o Health.o HomeCase.o main.o Panel.o Player.o SuperSoldier.o Troup.o
	$(CXX) $(CXXFLAGS) $^ -o $@

.PHONY: run clean

run: $(OUT_DIR)$(NAME)
	./$<

# Clean project
clean:
	rm -f *.o *~ core *.exe
