#include "quadratic_equation.h"


/**
 * @file quadratic_equation.c
 *
 * @brief contains body of functions required for solver
 *
 * @author Vladislav Fomberg
 *
 * @date 11/11/2020
 */

const double PRECISION = 0.0005;

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

