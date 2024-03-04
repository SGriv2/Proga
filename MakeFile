main:
	gcc -Wall -o app main.c IntVector.c
run:
	./app
clear:
	rv app
test:
	gcc -Wall test.c
run_test:
	./a.out