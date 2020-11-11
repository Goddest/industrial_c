#include "quadratic_equation.h"

/**
 * @file tests.c 
 * 
 * @brief contains several tests for quadratic solver
 *
 * @author Vladislav Fomberg
 *
 * @date 11/11/2020
 */

void test_quadratic_equation(int n, double x1, double x2, double a, double b, double c);
/**
 * compares via assert with given answer quadratic equation solver 
 *
 * @param [in] n: right number of roots
 * @param [in] x1: first right root
 * @param [in] x2: second right root
 * @param [in] a: coefficient at x^2
 * @param [in] b: coefficient at x
 * @param [in] c: constant coefficient
 */

void test_quadratic_equation(int n, double x1, double x2, double a, double b, double c){

	assert(!(isnan(a)));
	assert(!(isnan(b)));
	assert(!(isnan(c)));

	double first_root = 0;
	double second_root = 0;

	int number_of_roots = 0;
	number_of_roots = solve_square_equation(a, b, c, &first_root, &second_root);
	assert(number_of_roots == n);
	switch (number_of_roots){
		case 0:
			break;
		case 1:
			assert(x1 == first_root);
			break;
		case 2:
			if (compare_doubles(x1, first_root)){
				assert(x1 == first_root);
				assert(x2 == second_root);
			} else {
				assert(x1 == second_root);
				assert(x2 == first_root);
			}
			break;
		default:
			break;
	}
}

int main(){
	test_quadratic_equation(0, 0, 0, 1, -1, 3);
	test_quadratic_equation(2, -0.5, 1, 2, -1, -1);
	test_quadratic_equation(1, 1, 0, 2, -4, 2);
	test_quadratic_equation(0, 0, 0, 0, 0, 3);
	test_quadratic_equation(2, 0, 1, 1, -1, 0);
	printf("Tests passed.\n");
}

