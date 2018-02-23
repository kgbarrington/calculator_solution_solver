// calculation_functions.cpp
#include "stdafx.h"
#include "number_manipulation.h"
#include <math.h>
#include <iostream>
#include <sstream>

// ************************* REMOVE LAST VALUE ****************************************
std::string convert_to_string(double given_value)
{
	
	std::stringstream ss;
	ss.precision(4);
	ss << given_value;
	std::cout << "ss " << ss.str() << std::endl;
	std::string string_value = ss.str();
	return string_value;
}

std::string remove_last_char(std::string given_value_string)
{
	given_value_string.pop_back();
	return given_value_string;
}

double convert_to_double(std::string given_value_string)
{
	double given_value = stod(given_value_string);
	return given_value;
}

double remove_last_value(double given_value)
{

	// Check to make sure that the value is not a single digit integer. If it is, return 0.0
	if (given_value > -10 && given_value < 10)
	{
		double intpart;

		if ( (std::modf(given_value, &intpart)) == 0)
		{
			return 0.0;
		}
	}
	else
	{
		std::string string_value = convert_to_string(given_value);
		//std::cout << "String value " + string_value << std::endl;
		string_value = remove_last_char(string_value);
		//std::cout << "String value removed " + string_value << std::endl;
		double new_value = convert_to_double(string_value);
		//std::cout << "Numeric Value: " << new_value << std::endl;
		return new_value;
	}

	
}

//******************************** ADD TO END OF VALUE *****************************
std::string add_to_end_char(std::string given_value_string, std::string number_to_append)
{
	given_value_string.append(number_to_append);
	return given_value_string;
}

double add_to_end_of_value(double given_value, double value_to_append)
{
	std::string string_value = convert_to_string(given_value);
	std::string char_value_to_append = convert_to_string(value_to_append);
	string_value = add_to_end_char(string_value, char_value_to_append);
	double new_value = convert_to_double(string_value);
	return new_value;
}

//***************************** PERMUTATION HANDLING ******************************

void get_permutation_representaiton(std::vector<std::vector<int> > &permutation_list_rep,
	std::vector<int> permutation, int num_operators, int number_moves, int index, int &total_count)
{
	int i;
	// Stop recursion
	if (index == number_moves)
	{
		permutation_list_rep[total_count] = permutation;
		/*for (size_t x = 0, xlen = number_moves; x < xlen; x++)
		{
			std::cout << permutation_list_rep[total_count][x];
		}
		std::cout << std::endl;*/
		total_count += 1;
	}
	else
	{
		for (i = 0; i < num_operators; i++)
		{
			permutation[index] = i;
			get_permutation_representaiton(permutation_list_rep, permutation, num_operators, number_moves, index + 1, total_count);
		}
	}
}

void create_permutation_list(std::vector<std::vector<Operations*> > &permutation_list, std::vector<std::vector<int> > &permutation_list_rep,
	std::vector<Operations*> &operator_list, int num_moves)
{
	for (size_t i = 0, ilen = permutation_list.size(); i < ilen; i++)
	{
		//std::cout << "First Oper set: ";
		for (int j = 0; j < num_moves; j++)
		{
			int oper_select = permutation_list_rep[i][j];
			//std::cout << oper_select;
			permutation_list[i].push_back(operator_list[oper_select]);
		}
		//std::cout << std::endl;
	}

}

int get_number_permutations(std::vector<Operations*> &operation_list, int number_moves)
{
	int num_permutation = pow( operation_list.size(), number_moves);
	return num_permutation;
}

int get_number_operations(std::vector<Operations*> &operation_list)
{
	return operation_list.size();
}