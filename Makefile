all: main tests

main: main.c calculator.c
	gcc -o calculator -g main.c calculator.c

tests: unit_tests.c calculator.c
	gcc -o unit_tests -fprofile-arcs -ftest-coverage -O0 unit_tests.c calculator.c
	./unit_tests

clean:
	rm -f mayhem_tests unit_tests calculator  *.gc*
	rm -Rf calculator.dSYM
