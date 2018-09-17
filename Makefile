CXX = g++
CFLAGS = $(CXX) -c -Wall -Werror
OBJECTS = build/main.o build/random_training.o build/classic_training.o build/game.o
.PHONY: all clean

all: bin build bin/prog

bin/prog: $(OBJECTS)
	$(CXX) $(OBJECTS) -o bin/prog

build/main.o: src/main.cpp src/Header.h
	$(CFLAGS) src/main.cpp -o build/main.o

build/random_training.o: src/random_training.cpp src/Header.h
	$(CFLAGS) src/random_training.cpp -o build/random_training.o

build/classic_training.o: src/classic_training.cpp src/Header.h
	$(CFLAGS) src/classic_training.cpp -o build/classic_training.o

build/game.o: src/game.cpp src/Header.h
	$(CFLAGS) src/game.cpp -o build/game.o

bin:
	mkdir bin
build:
	mkdir build
clean:
	-rm -rf build/*.o bin/*.exe