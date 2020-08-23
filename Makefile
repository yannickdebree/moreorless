.PHONY: all
all: build run

.PHONY: build
build:
	gcc -o moreorless main.c -lm

.PHONY: run
run: moreorless
	./moreorless

moreorless: build