main:
	gcc main.c quadratic_equation.c -o main -lm

tests:
	gcc tests.c quadratic_equation.c -o test -lm

clean:
	rm -f *.0
	rm -f *~
	rm -f main
	rm -f test
