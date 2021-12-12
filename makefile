all: compile run

compile:
	gcc -o ./bin/main ./src/main.c

run:
	./bin/main