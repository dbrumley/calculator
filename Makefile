all: main tests mayhem_tests

main: main.c calculator.c
	gcc -o calculator -g main.c -O0 calculator.c

tests: unit_tests.c calculator.c
	gcc -o unit_tests -fprofile-arcs -ftest-coverage -O0 unit_tests.c calculator.c
	./unit_tests

mayhem_tests: mayhem_tests.c calculator.c
	gcc -o mayhem_tests -g -O0 mayhem_tests.c calculator.c

clean:
	rm -f mayhem_tests unit_tests calculator  *.gc*
	rm -Rf calculator.dSYM
