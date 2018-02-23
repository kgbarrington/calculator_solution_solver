#include "stdafx.h"
#include "input_handle.h"
#include <iostream>

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
                  double &start_value, int &number_moves)
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
*   Return:     double indicating goal value.
*/
double get_goal_value()
{
    double goal_value;

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
*   Return:     double indicating starting value.
*/
double get_start_value()
{
    double start_value;

    std::cout << "What is the starting value? : ";
    std::cin >> start_value;
    std::cout << std::endl;

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
    int number_moves;

    std::cout << "What are the maximum moves allowed? : ";
    std::cin >> number_moves;
    std::cout << std::endl;

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
        std::cin >> selection;
        std::cout << std::endl;

        if (selection < 0 || selection > 6)
        {
            std::cout << "Invalid selection..." << std::endl;
        }
        else { valid_selection = true; }
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
void handle_addition_selection(std::vector <Operations*> &operator_list, double start_value)
{
    double value_to_add;
    bool valid_value = false;

    while (!valid_value) // Prevent user from using invalid numbers
    {
        std::cout << "You have selected addition. Please enter a non-zero number: ";
        std::cin >> value_to_add;
        std::cout << std::endl;

        if (value_to_add == 0)
        {
            std::cout << "You have entered an incorrect value!" << std::endl;
        }
        else
        {
            valid_value = true;
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
void handle_multiplication_selection(std::vector <Operations*> &operator_list, double start_value)
{
    double factor;

    std::cout << "You have selected multiplication. Please enter a factor: ";
    std::cin >> factor;
    std::cout << std::endl;
    
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
void handle_division_selection(std::vector <Operations*> &operator_list, double start_value)
{
    double divisor;
    bool valid_value = false;
    
    while (!valid_value)
    {
        std::cout << "You have selected division. Please enter a non-zero divisor: ";
        std::cin >> divisor;
        std::cout << std::endl;

        if (divisor == 0)
        {
            std::cout << "You have entered an incorrect value!" << std::endl;
        }
        else
        {
            valid_value = true;
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
void handle_add_value_selection(std::vector <Operations*> &operator_list, double start_value)
{
    double value_to_add;
    double intpart;
    double decpart;

    std::cout << "You have selected to add digits to the end of the value. Please enter an integer: ";
    std::cin >> value_to_add;
    std::cout << std::endl;

    decpart = std::modf(start_value, &intpart);

    if (decpart != 0)
    { 
        std::cout << "You have entered a non integer. Removing decimal portion..." << std::endl;

        value_to_add = intpart;

        std::cout << "Value to add is now " << intpart << std::endl;
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
void handle_reverse_order_selection(std::vector <Operations*> &operator_list, double start_value)
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
void handle_remove_value_selection(std::vector <Operations*> &operator_list, double start_value)
{
    std::cout << "You have selected to remove the last value. Operator has been added." << std::endl;

    operator_list.push_back(new Remove_last_val(start_value));
}