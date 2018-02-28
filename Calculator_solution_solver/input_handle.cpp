// input_handle.cpp
// Written by Kasey Barrington, kgbarrington@gmail.com

#include "stdafx.h"
#include "input_handle.h"
#include <iostream>

/*
*   Summary:    This function checks the user input to ensure that the value is
*               an integer, allowing for negative integers as well. The function
*    
*   Params:     word:   The word to be checked for only valid signed integer characters.
*
*   Return:     bool
*
*/
bool isSignedInt(const std::string word)
{
    std::size_t found = word.find_first_not_of("-0123456789");

    if (found != std::string::npos)
    {
        std::cout << "The character cannot be an integer: " << word[found] << std::endl;

        return false;
    }
    else
    {
        return true;
    }

}

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
void do_user_menu(std::vector <Operations*> &operator_list, int &goal_value,
                  int &start_value, int &number_moves)
{
    int selection   = -1;
    
    goal_value      = get_goal_value();
    start_value     = get_start_value();
    number_moves    = get_number_moves();
    
    bool remove_value_picked = false;

    while (selection != 0) // 0 is exit menu command
    {
        selection = print_operator_selection_menu(); // retrieve user menu selection

        if (selection == 1)
        {
            handle_addition_selection(operator_list, start_value);
        }
        else if (selection == 2)
        {
            handle_multiplication_selection(operator_list, start_value);
        }
        else if (selection == 3)
        {
            handle_division_selection(operator_list, start_value);
        }
        else if (selection == 4)
        {
            handle_add_value_selection(operator_list, start_value);
        }
        else if (selection == 5)
        {
            handle_remove_value_selection(operator_list, start_value);
        }
        else if (selection == 6)
        {
            handle_reverse_order_selection(operator_list, start_value);
        }
        else if (selection == 0)
        {
            std::cout << "Done selecting operators. Moving on..." << std::endl;
        }
    }
}

/*
*   Summary:    This function gets the goal value from the user.
*
*   Params:     none
*
*   Return:     int indicating goal value.
*/
int get_goal_value()
{
    int goal_value;

    std::cout << "What is the goal value? : ";
    std::cin >> goal_value;
    std::cout << std::endl;

    return goal_value;
}

/*
*   Summary:    This function gets the starting value from the user.
*
*   Params:     none
*
*   Return:     int indicating starting value.
*/
int get_start_value()
{
    std::string input_value;
    int start_value;


    std::cout << "What is the starting value? : ";
    std::cin >> input_value;
    std::cout << std::endl;

    while (!isSignedInt(input_value)) // Verify correct input
    {
        std::cout << "What is the starting value? : ";
        std::cin >> input_value;
        std::cout << std::endl;
    }

    start_value = std::stoi(input_value);

    return start_value;
}

/*
*   Summary:    This function gets the number of moves from the user.
*
*   Params:     none
*
*   Return:     int indicating number of moves.
*/
int get_number_moves()
{
    std::string input_value;
    int number_moves;

    std::cout << "What are the maximum moves allowed? : ";
    std::cin >> input_value;
    std::cout << std::endl;

    while (!isSignedInt(input_value)) // Verify correct input
    {
        std::cout << "What are the maximum moves allowed? : ";
        std::cin >> input_value;
        std::cout << std::endl;
    }

    number_moves = std::stoi(input_value);

    return number_moves;
}

/*
*   Summary:    This function prints the operator selection menu and gets the 
*               selection from the user.
*
*   Params:     none
*
*   Return:     int indicating the user menu selection.
*/
int print_operator_selection_menu()
{
    std::string input_value;
    int selection;
    bool valid_selection = false;
    
    while (!valid_selection) // Prevent user from selection a non-option.
    {
        std::cout << "Select an operation:" << std::endl;
        std::cout << "1. Addition" << std::endl;
        std::cout << "2. Multiplication" << std::endl;
        std::cout << "3. Division" << std::endl;
        std::cout << "4. Add value to end of number" << std::endl;
        std::cout << "5. Remove last value of number" << std::endl;
        std::cout << "6. Reverse number order" << std::endl;
        std::cout << "0. Stop operator selection" << std::endl;
        std::cout << "Enter Selection: ";
        std::cin >> input_value;
        std::cout << std::endl;
                
        if (!isSignedInt(input_value)) // Verify correct input
        {
            std::cout << "Please use an integer value." << std::endl;
        }
        else if (isSignedInt(input_value))
        {
            selection = std::stoi(input_value);

            if (selection < 0 || selection > 6) // Verify correct menu selection
            {
                std::cout << "Invalid selection..." << std::endl;
            }
            else { valid_selection = true; } // All checks are good, proceed.
        }        
    }

    return selection;
}

/*
*   Summary:    This function gets the value to be added for the addition operation. An Addition
*               object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_addition_selection(std::vector <Operations*> &operator_list, int start_value)
{
    std::string input_value;
    int value_to_add;
    bool valid_value = false;

    while (!valid_value) // Prevent user from using invalid numbers
    {
        std::cout << "You have selected addition. Please enter a non-zero integer: ";
        std::cin >> input_value;
        std::cout << std::endl;

        if (!isSignedInt(input_value)) // Verify correct input
        {
            std::cout << "Please use an integer value." << std::endl;
        }
        else if (isSignedInt(input_value))
        {
            value_to_add = std::stoi(input_value);

            if (value_to_add == 0)
            {
                std::cout << "You have entered an invalid value!" << std::endl;
            }
            else { valid_value = true; } // All checks are good, proceed.
        }        
    }
    operator_list.push_back(new Addition(start_value, value_to_add));
    
}

/*  Summary:    This function gets the value for the multiplication factor for the multiplication
*               operation. A Multiply object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_multiplication_selection(std::vector <Operations*> &operator_list, int start_value)
{
    std::string input_value;
    int factor;
    bool valid_value = false;
        
    while (!valid_value) // Prevent user from using invalid numbers
    {
        std::cout << "You have selected multiplication. Please enter a non-zero integer factor: ";
        std::cin >> input_value;
        std::cout << std::endl;

        if (!isSignedInt(input_value)) // Verify correct input
        {
            std::cout << "You have entered an invalid value!" << std::endl;
        }
        else if (isSignedInt(input_value))
        {
            factor = std::stoi(input_value);

            if (factor == 0)
            {
                std::cout << "0 is not a valid number." << std::endl;
            }
            else { valid_value = true; } // All checks are good, proceed.
        }
    }

    operator_list.push_back(new Multiply(start_value, factor));
}

/*
*   Summary:    This function gets the value for the divisor for the division operation. 
*               A Divide object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_division_selection(std::vector <Operations*> &operator_list, int start_value)
{
    std::string input_value;
    int divisor;
    bool valid_value = false;
    
    while (!valid_value)
    {
        std::cout << "You have selected division. Please enter a non-zero divisor: ";
        std::cin >> input_value;
        std::cout << std::endl;

        if (!isSignedInt(input_value)) // Verify correct input
        {
            std::cout << "You have entered an invalid value!" << std::endl;
        }
        else if (isSignedInt(input_value))
        {
            divisor = std::stoi(input_value);

            if (divisor == 0)
            {
                std::cout << "0 is not a valid number." << std::endl;
            }
            else { valid_value = true; } // All checks are good, proceed.
        }        
    }
    
    operator_list.push_back(new Divide(start_value, divisor));
}

/*
*   Summary:    This function gets the to be added to for the Add Value to End
*               operation. An Add_last_val object is then added to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_add_value_selection(std::vector <Operations*> &operator_list, int start_value)
{
    std::string input_value;
    int value_to_add;
    bool valid_value = false;
    int intpart;
    int decpart;

    while (!valid_value)
    {
        std::cout << "You have selected to add digits to the end of the value. Please enter a positive integer: ";
        std::cin >> input_value;
        std::cout << std::endl;

        if (!isSignedInt(input_value)) // Verify correct input
        {
            std::cout << "You have entered an invalid value!" << std::endl;
        }
        else if (isSignedInt(input_value))
        {
            value_to_add = std::stoi(input_value);

            if (value_to_add < 0)
            {
                std::cout << "You entered an invalid (negative) number." << std::endl;
            }
            else { valid_value = true; } // All checks are good, proceed.
        }
    }

    operator_list.push_back(new Add_last_val(start_value, value_to_add));
}

/*
*   Summary:    This function adds a Reverse_order object to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_reverse_order_selection(std::vector <Operations*> &operator_list, int start_value)
{
    std::cout << "You have selected to reverse number order. Operator has been added." << std::endl;

    operator_list.push_back(new Reverse_order(start_value));
}

/*
*   Summary:    This function adds a Remove_last_val object to the vector operator_list.
*
*   Params:     operator_list:  Vector that stores the list of math operations selected by the user.
*               start_value:    The starting value selected by the user.
*
*   Return:     void
*/
void handle_remove_value_selection(std::vector <Operations*> &operator_list, int start_value)
{
    std::cout << "You have selected to remove the last value. Operator has been added." << std::endl;

    operator_list.push_back(new Remove_last_val(start_value));
}