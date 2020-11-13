#include "quadratic_equation.h"

/**
 * @file main.c 
 *
 * @brief solves quadratic equation, input from standard stream keyboard
 *
 * @author Vladislav Fomberg
 *
 * @date 11/11/2020
 */ 

int main(){

	printf("enter coefficients of the square equation \n");
	double a, b, c;
	scanf("%lg%lg%lg", &a, &b, &c);
	
	assert(!(isnan(a)));
	assert(!(isnan(b)));
	assert(!(isnan(c)));

	int roots_found = -1;

	double first_root = 0, second_root = 0;

	roots_found = solve_square_equation(a, b, c, &first_root, &second_root);
	
	assert(!(isnan(first_root)));
	assert(!(isnan(second_root)));

	switch(roots_found){
		case 0:
			printf("zero roots found \n");
			break;
		case 1:
			printf("a single root found: x = %f \n", first_root);
			break;
		case 2:
			printf("two roots found: x_1 = %f; x_2 = %f; \n", first_root, second_root);
			break;
		case 3:
			printf("infinite roots found, aborting...\n");
			break;
		default:
			printf("Error occured, aborting...\n");
			break;
	}

	return 0;
}

