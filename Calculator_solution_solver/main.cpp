// Calculatorsolutionsolver.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <math.h>
#include <string>
#include <iostream>
#include "number_manipulation.h"
#include "input_handle.h"
#include "operator_classes.h"


int main()
{
	std::vector<Operations*> operation_list;

	double goal_value, start_value;
	int number_moves;
	int number_operations;
	int total_count = 0;
	int index = 0;
	int number_permutations;

	do_user_menu(operation_list, goal_value, start_value, number_moves);
	
	number_operations = operation_list.size();
	number_permutations = get_number_permutations(operation_list, number_moves);
	std::vector<std::vector<Operations*> > permutation_list(number_permutations);
	std::vector<std::vector<int> > permutation_list_rep(number_permutations);
	std::vector<int> permutation_rep(number_moves);

	get_permutation_representaiton(permutation_list_rep, permutation_rep, number_operations, number_moves, index, total_count);
	create_permutation_list(permutation_list, permutation_list_rep, operation_list, number_moves);

	bool first = true;
	int count = 1;
	for (size_t i = 0, ilen = permutation_list.size(); i < ilen; i++)
	{
		double new_value;

		std::cout << "Trying permutation " << count << std::endl;

		for (size_t j = 0; j < number_moves; j++)
		{
			if (first)
			{
				std::cout << "First is True " << std::endl;
				permutation_list[i][j]->set_given_value(start_value);
				std::cout << "Value: " << permutation_list[i][j]->get_given_value() << std::endl;
				permutation_list[i][j]->execute_function();
				permutation_list[i][j]->print_operation_type();				
				new_value = permutation_list[i][j]->get_given_value();
				std::cout << "Value: " << new_value << std::endl;


				if (new_value == goal_value)
				{
					std::cout << "Goal Value found! " << std::endl;
					abort();
				}

				first = false;
			}
			else
			{
				std::cout << "First is False " << std::endl;
				permutation_list[i][j]->set_given_value(new_value);
				permutation_list[i][j]->execute_function();
				permutation_list[i][j]->print_operation_type();
				new_value = permutation_list[i][j]->get_given_value();
				std::cout << "Value: " << new_value << std::endl;

				if (new_value == goal_value)
				{
					std::cout << "Goal Value found! " << std::endl;
					abort();
				}
			}
		}

		first = true;
		count++;
		std::cout << std::endl;
	}
	
	/*std::cout << "Printing List: \n";
	for (size_t i = 0, size = permutation_list_rep.size(); i < size; ++i)
	{
		for (size_t j = 0; j < number_moves; j++)
		{
			std::cout << permutation_list_rep[i][j];
		}
		
		std::cout << std::endl;
	}*/

    return 0;
}
