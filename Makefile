.PHONY: build all clean test

all: build run

FLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 

build:
	gcc conway.c -o conway.out $(FLAGS)
	
clean:
	rm -f *.out

run:
	./conway.out

