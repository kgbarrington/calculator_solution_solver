// calculation_functions.h

#pragma once
#ifndef _number_manipulation_h
#define _number_manipulation_h

#include <vector>
#include <string>
#include "operator_classes.h"

//***************************** REMOVE LAST VALUE
std::string convert_to_string(double given_value);

std::string remove_last_char(std::string given_value_string);

double convert_to_double(std::string given_value_string);

double remove_last_value(double given_value);

//***************************** ADD DIGIT TO END OF VALUE
std::string add_to_end_char(std::string given_value_string, std::string number_to_append);

double add_to_end_of_value(double given_value, double value_to_append);

//***************************** PERMUTATION FUNCTIONS
void get_permutation_representaiton(std::vector<std::vector<int> > &permutation_list_rep,
	std::vector<int> permutation, int num_operators, int number_moves, int index, int &total_count);

void create_permutation_list(std::vector<std::vector<Operations*> > &permutation_list,
	std::vector<std::vector<int> > &permutation_list_rep, std::vector<Operations*> &operator_list,
	int num_moves);

int get_number_permutations(std::vector<Operations*> &operation_list, int number_moves);

int get_number_operations(std::vector<Operations*> &operation_list);

#endif

