test: build run

build:
	gcc -o moreorless main.c -lm

run:
	./moreorless