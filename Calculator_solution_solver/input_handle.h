#pragma once
#ifndef _input_handle_h
#define _input_handle_h

#include <vector>
#include "operator_classes.h"

/*
*   Summary:    This function handles all user interaction for operation selection and
*               initial values. The vector operator_list will store the operations selected
*               by the user.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               goal_value:     The target value selected by the user.
*               start_value:    The starting value selected by the user.
*               number_moves:   The number of moves to get from the start value to the end value,
*                                    selected by the user.
*
*   Return:     Void
*/
void do_user_menu(std::vector <Operations*> &operator_list, double &goal_value, 
                  double &start_value, int &number_moves);

/*
*   Summary:    This function gets the goal value from the user.
*
*   Params:     none
*
*   Return:     double indicating goal value.
*/
double get_goal_value();

/*
*   Summary:    This function gets the starting value from the user.
*
*   Params:     none
*
*   Return:     double indicating starting value.
*/
double get_start_value();

/*
*   Summary:    This function gets the number of moves from the user.
*
*   Params:     none
*
*   Return:     int indicating number of moves.
*/
int get_number_moves();

/*
*   Summary:    This function prints the operator selection menu and gets the
*               selection from the user.
*
*   Params:     none
*
*   Return:     int indicating the user menu selection.
*/
int print_operator_selection_menu();

/*
*   Summary:    This function gets the value to be added for the addition operation. An Addition
*               object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_addition_selection(std::vector <Operations*> &operator_list, double start_value);

/*  Summary:    This function gets the value for the multiplication factor for the multiplication
*               operation. A Multiply object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_multiplication_selection(std::vector <Operations*> &operator_list, double start_value);

/*
*   Summary:    This function gets the value for the divisor for the division operation.
*               A Divide object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_division_selection(std::vector <Operations*> &operator_list, double start_value);

/*
*   Summary:    This function gets the to be added to for the Add Value to End
*               operation. An Add_last_val object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_add_value_selection(std::vector <Operations*> &operator_list, double start_value);

/*
*   Summary:    This function adds a Reverse_order object to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_reverse_order_selection(std::vector <Operations*> &operator_list, double start_value);

/*
*   Summary:    This function adds a Remove_last_val object to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_remove_value_selection(std::vector <Operations*> &operator_list, double start_value);


#endif