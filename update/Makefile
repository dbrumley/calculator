all: main test mayhem_tests

main: main.c calculator.c
	gcc -o calculator -g main.c calculator.c

test: unit_tests.c calculator.c
	gcc -o unit_tests unit_tests.c calculator.c

mayhem_tests: mayhem_tests.c calculator.c
	gcc -o mayhem_tests -g mayhem_tests.c calculator.c

docker: calculator.c mayhem_tests.c main.c unit_tests.c
	docker buildx build --platform linux/amd64 -t dbrumley/calculator:latest --push .

clean:
	rm -f mayhem_tests unit_tests calculator calculator.dSYM
