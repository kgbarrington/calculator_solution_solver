// number_manipulation.cpp
// Written by Kasey Barrington, kgbarrington@gmail.com

#include "stdafx.h"
#include "number_manipulation.h"
#include <iostream>
#include <sstream>

/*
*   Summary:    This function converts an int to a string with a precision of 4.
*
*   Params:     given_value:    The value to be converted from double to string.
*
*   Return:     string of the converted double.
*/
std::string convert_to_string(int given_value)
{    
    std::string string_value;
    string_value = std::to_string(given_value);
    return string_value;
}

/*
*   Summary:    This function removes the last character of a string. It is used to
*               for the remove_last_value operation.
*
*   Params:     given_value:    The value to be have the last digit removed.
*
*   Return:     string of the new value.
*/
std::string remove_last_char(std::string given_value_string)
{
    given_value_string.pop_back();
    return given_value_string;
}

/*
*   Summary:    This function converts a string to a double.
*
*   Params:     given_value:    The value to be converted from string to double.
*
*   Return:     int of the converted string.
*/
int convert_to_int(std::string given_value_string)
{
    int given_value = stoi(given_value_string);
    return given_value;
}

/*
*   Summary:    This function removes the last value from a number.
*
*   Params:     given_value:    The value to have the last digit removed.
*
*   Return:     int with last digit removed.
*/
int remove_last_value(int given_value)
{
    // Check to make sure that the value is not a single digit integer. If it is, return 0
    if (given_value > -10 && given_value < 10)
    {
        return given_value;
    }
    else
    {
        std::string string_value = convert_to_string(given_value);
        string_value = remove_last_char(string_value);
        int new_value = convert_to_int(string_value);
        return new_value;
    }
}

/*
*   Summary:    This function adds a character(s) to the end of a string. It is used to
*               for the add_to_end_of_value operation.
*
*   Params:     given_value_string:     string to have a character added to.
*               number_to_append:       string  to be added.
*
*   Return:     string of the new value.
*/
std::string add_to_end_char(std::string given_value_string, std::string number_to_append)
{
    given_value_string.append(number_to_append);
    return given_value_string;
}

/*
*   Summary:    This function adds an integer to the end of another integer.
*
*   Params:     given_value:        string to have a character added to.
*               value_to_append:    integer to be added.
*
*   Return:     string of the new value.
*/
int add_to_end_of_value(int given_value, int value_to_append)
{
    std::string string_value = convert_to_string(given_value);
    std::string char_value_to_append = convert_to_string(value_to_append);
    string_value = add_to_end_char(string_value, char_value_to_append);
    double new_value = convert_to_int(string_value);
    return new_value;
}

/*
*   Summary:    This function calculates the total number of math operations.
*
*   Params:     operation_list:     A vector of all the math operations given by the user.
*
*   output:     int
*/
int get_number_operations(std::vector<Operations*> &operation_list)
{
    return operation_list.size();
}

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
int get_number_permutations(int number_operations, int number_moves)
{
    int num_permutation = pow(number_operations, number_moves);
    return num_permutation;
}

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
                                    std::vector<int> permutation, int num_operators, 
                                    int number_moves, int index, int &total_count)
{
    int i;
    if (index == number_moves) // Stop recursion
    {
        permutation_list_rep[total_count] = permutation;
        total_count += 1;
    }
    else
    {
        for (i = 0; i < num_operators; i++)
        {
            permutation[index] = i;
            get_permutation_representaiton(permutation_list_rep, permutation, num_operators, 
                                           number_moves, index + 1, total_count);
        }
    }
}

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
                             std::vector<std::vector<int> > &permutation_list_rep,
                             std::vector<Operations*> &operator_list, int num_moves)
{
    for (size_t i = 0, ilen = permutation_list.size(); i < ilen; i++) // For each possible permutation
    {
        for (int j = 0; j < num_moves; j++) // For each move
        {
            int oper_select = permutation_list_rep[i][j]; // Get the operation
            permutation_list[i].push_back(operator_list[oper_select]); // Insert operation into the list.
        }
    }
}



