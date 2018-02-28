// Calculator Solution Solver
// Written by Kasey Barrington, kgbarrington@gmail.com
// 
// Github: https://github.com/kgbarrington/calculator_solution_solver.git
// "Calculator: The Game": https://play.google.com/store/apps/details?id=com.sm.calculateme&hl=en
//
// This program will solve puzzles from the mobile game "Calculator: The Game"
// The goal of the game is to use mathematical operatorations in order to achieve 
// a determined value given: a starting value, limited number of moves, 
// and predetermined mathematical operations. 
//
// Example: Get to the number 14 starting from 5 using +1 and x2, in three moves.
// Soulution: 5 -> +1 -> 6 -> +1 -> 7 -> x2 -> 14
//
// This program takes the initial conditions of the puzzle and finds the solution 
// via brute force. It is not optimized, but it gets the job done!
//
//                              ***WARNING*** 
// Large permutations (ie - many operations and many number of moves) result in 
// large computation. Be judicious. Number of permutations 
// are (number operators)^(number moves).

// TODO:    Track down a crash which only seems to appear with large permutations. 
//          It happens while every math permutation is being attempted. 
//          
//          The integer division needs to check for a remainder to avoid false 
//          positives. A method of skipping a permutation if this occurs needs to 
//          be put in place. Possibly adding a private member to the operation 
//          class "bool is_valid" could solve the problem. After each math operation,
//          that bool could be checked to determine if the permutation should procede. 
//
//          Optimization could be improved with the math operations. For example adding 
//          3 and adding 2 is the same as adding 2 and adding 3. This will have to be 
//          implemented after the permutation list is constructed.

#include "stdafx.h"
#include <math.h>
#include <string>
#include <iostream>
#include "number_manipulation.h"
#include "input_handle.h"
#include "operator_classes.h"


int main()
{
    std::vector<Operations*> operation_list; // Stores all math operations selected by the user.

    int goal_value, start_value;
    int number_moves;
    int number_operations;
    int total_count = 0;
    int index = 0;
    int number_permutations;

    do_user_menu(operation_list, goal_value, start_value, number_moves);            // Get the math operations, etc..
    
    number_operations = operation_list.size();
    number_permutations = get_number_permutations(number_operations, number_moves); // Calculate total number of permutations.
    
    std::vector<std::vector<Operations*> > permutation_list(number_permutations);   // Allocate space for optimization.
    std::vector<std::vector<int> > permutation_list_rep(number_permutations);       // " "
    std::vector<int> permutation_rep(number_moves);                                 // " "

    get_permutation_representaiton(permutation_list_rep, permutation_rep, number_operations,    // Get an integer representation of 
                                   number_moves, index, total_count);                           // math object permutations.
    
    create_permutation_list(permutation_list, permutation_list_rep, 
                            operation_list, number_moves);                          // Create permutation list of math object operators.

    bool first = true;
    int count = 1;
    std::vector<std::vector<Operations*> > success_list;                    // Store all successful permutations 
    
    for (size_t i = 0, ilen = permutation_list.size(); i < ilen; i++)
    {
        std::vector<Operations*> permutation;
        int new_value;

        std::cout << "Trying permutation " << count << std::endl;

        for (size_t j = 0; j < number_moves; j++)
        {
            if (first)
            {
                permutation_list[i][j]->set_given_value(start_value);       // Set the start value in the math operator object.
                permutation_list[i][j]->execute_function();                 // execute math operator function
                new_value = permutation_list[i][j]->get_given_value();      // Set modified value.

                permutation.push_back(permutation_list[i][j]);              // store possible successful permutation

                if (new_value == goal_value)
                {
                    success_list.push_back(permutation);                // If permutation is successful, add it to the list 
                }                                                       // of successful permutations.

                first = false;
            }
            else if (!first && new_value != goal_value)
            {
                permutation_list[i][j]->set_given_value(new_value);     // Set the modified value in the math operator object.
                permutation_list[i][j]->execute_function();             // execute math operator function.
                new_value = permutation_list[i][j]->get_given_value();  // Set modified value .

                permutation.push_back(permutation_list[i][j]);          // Add math operator list to temporary vector.

                if (new_value == goal_value)
                {
                    success_list.push_back(permutation);                // If permutation is successful, add it to the list of successful permutations.
                }
            }
        }

        permutation.clear();        // Clear temporary permutation list.
        first = true;
        count++;
    }


    if (success_list.size() != 0) // If a successful permutation exists
    {
        std::cout << "\n\nTotal number of successful permutations: " << success_list.size() << std::endl;
        
        int max = 0;
        int min = 0;
        first = true;
        int shortest_position = 0;
        int longest_position = 0;

        for (size_t i = 0, ilen = success_list.size(); i < ilen; i++) // determine longest and shortest permutations
        {
            if (first)
            {
                min = success_list[i].size();
                max = min;
                first = false;
            }
            else
            {
                int test_val = success_list[i].size();
                if (test_val < min)
                {
                    min = test_val;
                    shortest_position = i;
                }
                else if (test_val > max)
                {
                    max = test_val;
                    longest_position = i;
                }
            }
        }

        std::cout << std::endl << "Minimum Moves: " << min << std::endl;
        std::cout << "Maxmimum Moves: " << max << std::endl << std::endl;

        std::cout << "Shortest method to get to target number(" << goal_value << "): " << std::endl;
        std::cout << "Starting Value: " << start_value << std::endl;

        first = true;
        int new_value;

        for (size_t i = 0, ilen = success_list[shortest_position].size(); i < ilen; i++) // Print shortest permutation
        {
            if (first)
            {
                success_list[shortest_position][i]->set_given_value(start_value);       // Set the modified value in the math operator object.
                success_list[shortest_position][i]->execute_function();                 // execute math operator function.
                success_list[shortest_position][i]->print_operation_type();             // Print operator type.
                new_value = success_list[shortest_position][i]->get_given_value();      // Set modified value .
                std::cout << "Start Value becomes: " << new_value << std::endl;         // Print modified value.

                first = false;
            }
            else
            {
                success_list[shortest_position][i]->set_given_value(new_value);         // Set the modified value in the math operator object.
                success_list[shortest_position][i]->execute_function();                 // execute math operator function.
                success_list[shortest_position][i]->print_operation_type();             // Print operator type.
                new_value = success_list[shortest_position][i]->get_given_value();      // Set modified value .
                std::cout << "Value becomes: " << new_value << std::endl;               // Print modified value.

                if (new_value == goal_value)
                {
                    std::cout << "Goal value " << goal_value << " achieved!" << std::endl;
                }
            }            
        }
    }
    else // If no permutation exists, cry. 
    {
        std::cout << "Attempted all permutations (" << number_permutations << ") ";
        std::cout << "and there is no possible method to get to the target value." << std::endl;
    }

    return 0;
}

