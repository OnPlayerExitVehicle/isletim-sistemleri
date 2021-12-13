all: compile run

compile:
	gcc -I ./include -c ./src/colors.c -o ./lib/colors.o 
	gcc -I ./include -c ./src/parser.c -o ./lib/parser.o 
	gcc -I ./include -o ./bin/main ./src/main.c ./lib/colors.o ./lib/parser.o

run:
	./bin/main