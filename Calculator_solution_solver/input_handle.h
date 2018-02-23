#pragma once
#ifndef _input_handle_h
#define _input_handle_h

#include <vector>
#include "operator_classes.h"

void do_user_menu(std::vector <Operations*> &operator_list, double &goal_value, 
	double &start_value, int &number_moves);
double get_goal_value();
double get_start_value();
int get_number_moves();
int print_operator_selection_menu();
void handle_addition_selection(std::vector <Operations*> &operator_list, double start_value);
void handle_multiplication_selection(std::vector <Operations*> &operator_list, double start_value);
void handle_division_selection(std::vector <Operations*> &operator_list, double start_value);
void handle_add_value_selection(std::vector <Operations*> &operator_list, double start_value);
void handle_remove_value_selection(std::vector <Operations*> &operator_list, double start_value);
void handle_reverse_order_selection(std::vector <Operations*> &operator_list, double start_value);


#endif