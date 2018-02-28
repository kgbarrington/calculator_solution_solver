// calculation_functions.h
// Written by Kasey Barrington, kgbarrington@gmail.com
#pragma once
#ifndef _number_manipulation_h
#define _number_manipulation_h

#include <vector>
#include <string>
#include "operator_classes.h"

/*
*   Summary:    This function converts an int to a string with a precision of 4.
*
*   Params:     given_value:    The value to be converted from double to string.
*
*   Return:     string of the converted double.
*/
std::string convert_to_string(int given_value);

/*
*   Summary:    This function removes the last character of a string. It is used to
*               for the remove_last_value operation.
*
*   Params:     given_value:    The value to be have the last digit removed.
*
*   Return:     string of the new value.
*/
std::string remove_last_char(std::string given_value_string);

/*
*   Summary:    This function converts a string to a double.
*
*   Params:     given_value:    The value to be converted from string to double.
*
*   Return:     int of the converted string.
*/
int convert_to_int(std::string given_value_string);

/*
*   Summary:    This function removes the last value from a number.
*
*   Params:     given_value:    The value to have the last digit removed.
*
*   Return:     int with last digit removed.
*/
int remove_last_value(int given_value);

/*
*   Summary:    This function adds a character(s) to the end of a string. It is used to
*               for the add_to_end_of_value operation.
*
*   Params:     given_value_string:     string to have a character added to.
*               number_to_append:       string  to be added.
*
*   Return:     string of the new value.
*/
std::string add_to_end_char(std::string given_value_string, std::string number_to_append);

/*
*   Summary:    This function adds an integer to the end of another integer.
*
*   Params:     given_value:        string to have a character added to.
*               value_to_append:    integer to be added.
*
*   Return:     string of the new value.
*/
int add_to_end_of_value(int given_value, int value_to_append);

/*
*   Summary:    This function calculates the total number of math operations.
*
*   Params:     operation_list:     A vector of all the math operations given by the user.
*
*   output:     int
*/
int get_number_operations(std::vector<Operations*> &operation_list);

/*
*   Summary:    This function calculates the total number of permutations determined by
*               the number of moves and the number of math operations available. It is
*               calculated by (number of operations)^(number of moves).
*
*   Params:     operation_list:     The total number of operations.
*               number_moves:       The total number of moves.
*
*   output:     int
*/
int get_number_permutations(int number_operations, int number_moves);

/*
*   Summary:    This function takes the total number of moves and all of the math
*               operators and calculates every possible permutation of the math operators
*               given the possible number of moves. For example, if there are 2 operations
*               and 3 moves, there are 8 representations of 0,1 -> 000, 001, 010, 011, 100,
*               101, 110, 111. These values then correspond to a set of math operations in
*               the vector of math operators.
*
*   Params:     permutation_list_rep:   Vector of vectors of integer representations of all
*                                       possible permutations.
*               permutation:            Vector of integers representing a subset of permutations.
*               num_operators:          Number of math operations given by the user.
*               number_moves:           Total number of moves given by the user.
*               index:                  Used to stop recursion at the correct time. Starts at 0.
*               total_count:            Used to insert a permutation into the proper place inside
*                                       of permutation_list_rep.
*
*   Return:     void
*/
void get_permutation_representaiton(std::vector<std::vector<int> > &permutation_list_rep,
    std::vector<int> permutation, int num_operators, int number_moves, int index, int &total_count);

/*
*   Summary:    This function takes the numerical representation of all math operation permutations
*               ans assigns the correct math operators to each representation. These are
*               stored permutation_list, a vector of vectors of math operations.
*
*   Params:     permutation_list:       A vector of vectors of math operation objects. Each set of
*                                       child vectors represents a permutation.
*               permutation_list_rep:   A vector of vectors of integers that are mathmatical
*                                       representations of all possible permutations.
*               operator_list:          Vector of all math operations given by the user.
*               num_moves:              Total number of moves, given by the user.
*
*   Return:     void
*/
void create_permutation_list(std::vector<std::vector<Operations*> > &permutation_list,
    std::vector<std::vector<int> > &permutation_list_rep, std::vector<Operations*> &operator_list,
    int num_moves);

#endif

