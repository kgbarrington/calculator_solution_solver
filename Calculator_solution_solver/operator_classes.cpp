// operator_classes.cpp
// Written by Kasey Barrington, kgbarrington@gmail.com

#include "stdafx.h"
#include "operator_classes.h"
#include "number_manipulation.h"
#include <iostream>

/*
*   Parent class of math operations available to the user.
*/
Operations::Operations(int given_value)
{
    set_given_value(given_value);
    
}

void Operations::execute_function()
{
    std::cout << "Operation called without proper child class!" << std::endl;
}

std::string Operations::get_function_type()
{
    std::string func_type = "Operation called without proper child class!";
    return func_type;
}

void Operations::print_operation_type()
{
    std::cout << "Operation called without proper child class!" << std::endl;
}

int Operations::get_given_value()
{
    return (_given_value);
}

void Operations::set_given_value(int new_value)
{
    _given_value = new_value;
}

void Operations::set_type(std::string oper_type)
{
    _oper_type = oper_type;
}

/*
*   This class handles multiplication operations.   
*/

Multiply::Multiply(int given_value, int factor) : Operations(given_value)
{
    _factor = factor;
    set_type("Multiplication");
}

void Multiply::execute_function()
{
    int given = get_given_value();
    int new_val = given * _factor;
    set_given_value(new_val);
}

std::string Multiply::get_function_type()
{
    std::string func_type = "Multiply by " + std::to_string(_factor);
    return func_type;
}

void Multiply::print_operation_type()
{
    std::cout << get_function_type() << std::endl;
}

/*
*   This class handles division operations.
*   TODO: Handle false pisitives, by checking if value%divisor == 0
*/

Divide::Divide(int given_value, int divisor) : Operations(given_value)
{
    _divisor = divisor;
}

void Divide::execute_function()
{
    int given = get_given_value();
    int new_val = given / _divisor;
    set_given_value(new_val);
}

std::string Divide::get_function_type()
{
    std::string func_type = "Divide by " + std::to_string(_divisor);
    return func_type;
}

void Divide::print_operation_type()
{
    std::cout << get_function_type() << std::endl;
}

/*
*   This class handles addition operations.
*/

Addition::Addition(int given_value, int add_value) : Operations(given_value)
{
    _add_value = add_value;
}

void Addition::execute_function()
{
    int given = get_given_value();
    int new_val = given + _add_value;
    set_given_value(new_val);
}

std::string Addition::get_function_type()
{
    std::string func_type = "Adding " + std::to_string(_add_value);
    return func_type;
}

void Addition::print_operation_type()
{
    std::cout << get_function_type() << std::endl;
}

/*
*   This class handles removing the last digit from a number.
*   Example: Remove last digit from 423 -> 42.
*/

Remove_last_val::Remove_last_val(int given_value) : Operations(given_value) {}

void Remove_last_val::execute_function()
{
    int value = get_given_value();
    int new_value = remove_last_value(value);
    set_given_value(new_value);
}

std::string Remove_last_val::get_function_type()
{
    std::string func_type = "Removing last digit.";
    return func_type;
}

void Remove_last_val::print_operation_type()
{
    std::cout << get_function_type() << std::endl;
}

/*
*   This class handles adding a digit to the end of a number. 
*   Example: add 2 to the end of 4 -> 42.
*/

Add_last_val::Add_last_val(int given_value, int add_value) : Operations(given_value)
{
    _add_value = add_value;
}

void Add_last_val::execute_function()
{
    int value = get_given_value();
    int add_val = _add_value;
    int new_value = add_to_end_of_value(value, add_val);
    set_given_value(new_value);
}

std::string Add_last_val::get_function_type()
{
    std::string func_type = "Adding digit " + std::to_string(_add_value) + " to end of value.";
    return func_type;
}

void Add_last_val::print_operation_type()
{
    std::cout << get_function_type() << std::endl;
}

/*
*   This class handles reversing the order of digits.
*   Example: reverse 24 -> 42.
*/

Reverse_order::Reverse_order(int given_value) : Operations(given_value) 
{
    set_type("Reverse Order");
}

void Reverse_order::execute_function()
{
    int given_value = get_given_value();
    
    std::string given_value_string = convert_to_string(given_value);
   
    if (given_value > 0) // Check for negative sign.
    {
        std::reverse(given_value_string.begin(), given_value_string.end());
    }
    else if (given_value < 0 && given_value != 0) // If negative sign, reverse numbers only.
    {
        std::string temp_string = given_value_string.erase(0, 1);
        std::reverse(temp_string.begin(), temp_string.end());
        given_value_string = temp_string.insert(0, "-");
    }
    else // if value is zero, do nothing.
    {
        given_value_string = "0";
    }

    given_value = convert_to_int(given_value_string);
    set_given_value(given_value);
}

std::string Reverse_order::get_function_type()
{
    std::string func_type = "Reversing order of digits";
    return func_type;
}

void Reverse_order::print_operation_type()
{
    std::cout << get_function_type() << std::endl;
}