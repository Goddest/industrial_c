#ifndef QUADR_EQUATION_SOLVER_H
#define QUADR_EQUATION_SOLVER_H

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

	
/**
 * @file quadratic_equation.h
 *
 * @brief contains headers for all functions required for solver
 *
 * @author Vladislav Fomberg 
 *
 * @date 11/11/2020
 */



/*
 * Solves quadratic equation and returns number of roots
 * 
 * @param [in] a: coefficient at x^2
 * @param [in] b:  coefficient at x
 * @param [in] c: constant member
 *
 * @param [out] *first_root: pointer to first root
 * @param [out] *second_root: pointer to second root
 *
 * @return number of roots 
 */
int solve_square_equation(double a, double b, double c, double *first_root, double *second_root);


/*
 * Compares two doubles at the input
 *
 * @param [in] first_number: first double number to compare
 * @param [in] second_number: second double number to compare
 *
 * @return bool: are numbers equal with subtlety to precision
 */
int compare_doubles(double first_number, double second_number);

/*
 * Solves presented linear equation
 *
 * @param [in] b: coefficient at x
 * @param [in] c: constant member
 * 
 * @param [out] *root: pointer to root
 *
 * @return  number of roots, 3 for inf roots and 0 for no roots
 *
*/ 
int solve_linear_equation(double b, double c, double *root);

#endif //QUADR_EQUATION_SOLVER_H//

