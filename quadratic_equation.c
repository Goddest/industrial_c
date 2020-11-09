#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <assert.h>


const double PRECISION = 0.0005;

int solve_square_equation(double a, double b, double c, double *first_root, double *second_root);

/*
 * Function: solve_square_equation
 * _______________________________
 * solves a square equation: a*x^2 + b*x + c
 * 
 * Input:
 * a: coefficient at x^2
 * b: coefficient at x
 * c: constant member
 * *first_root: pointer to first root
 * *second_root: pointer to second root
 *
 * Output:
 * integer: number of roots 
*/

int compare_doubles(double first_number, double second_number);

/*
 * Function: compare_doubles
 * _________________________
 * compares two doubles at the input
 *
 * Input:
 * first_number: first double number to compare
 * second_number: second double number to compare
 *
 * Output:
 * bool: returns true if numbers are equal, returns false if numbers are not equal
 *
*/

int solve_linear_equation(double b, double c, double *root);

/*
 * Function: solve_linear_equation
 * _______________________________
 * solves presented linear equation
 *
 * Input:
 * b: coefficient at x
 * c: constant member
 * *root: pointer to root
 *
 * Output:
 * integer: return number of roots, 3 for inf roots and 0 for no roots
 *
*/ 

int main(){

	printf("enter coefficients of the square equation \n");
	double a, b, c;
	scanf("%lg%lg%lg", &a, &b, &c);
	
	/* check if input are not nans */	
	assert(!(isnan(a)));
	assert(!(isnan(b)));
	assert(!(isnan(c)));

	int roots_found = -1;

	double first_root = 0, second_root = 0;

	roots_found = solve_square_equation(a, b, c, &first_root, &second_root);
	
	/* check if function results are non nans */
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
			printf("two roots found: x_1 = %f; x_2=%f; \n", first_root, second_root);
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

int solve_square_equation(double a, double b, double c, double *first_root, double *second_root){
	assert(first_root != NULL);
	assert(second_root != NULL);
	assert(!(isnan(a)));
	assert(!(isnan(b)));
	assert(!(isnan(c)));

	if (compare_doubles (a, 0)){
		return solve_linear_equation(b, c, first_root);
	}
	else if (compare_doubles (c, 0)){
		*first_root = 0;
		return solve_linear_equation(a, b, second_root) + 1;
	} 
	else {
		double discriminant = b*b - 4*a*c;
		if (discriminant <= -PRECISION)
			return 0;
		else if (compare_doubles(discriminant, 0)){
			*first_root = -b / (2*a);
			return 1;
		} 
		else {
			double square_root = sqrt(discriminant);
			
			*first_root = (-b + square_root)/(2*a);
			*second_root = (-b - square_root)/(2*a);
			return 2;

		}
	}
}

int solve_linear_equation(double b, double c, double *root){
	assert(!(isnan(b)));
	assert(!(isnan(b)));
	if (compare_doubles(b, 0) && compare_doubles(c, 0)){
		return 3;
	}
	else if (compare_doubles(b, 0) && !(compare_doubles(c, 0))){
		return 0;
	}	
	else{
		*root = -c / b;
		return 1;	
	}
}

int compare_doubles(double a, double b){
	assert(!(isnan(a)));
	assert(!(isnan(b)));

	return (abs(a - b) <= PRECISION);
}


