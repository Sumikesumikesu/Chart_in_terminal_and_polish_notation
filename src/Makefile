GCC = gcc -Wall -Werror -Wextra

all: clang build

build:
	$(GCC) graph.c libs/stack.c libs/queue.c libs/parser.c libs/shunting_yard.c libs/calculator.c -o ../build/graph

clean:
	rm -rf ../build/graph

clang:
	cp ../materials/linters/.clang-format .
	clang-format -i *.c libs/*.c libs/include/*.h
	rm .clang-format

rebuild: clean all