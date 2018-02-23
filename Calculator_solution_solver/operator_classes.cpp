#include "stdafx.h"
#include "operator_classes.h"
#include "number_manipulation.h"
#include <iostream>

////////////////////////////////// OPERATIONS CLASS (PARENT) /////////////////////////////////////
Operations::Operations(double given_value)
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

double Operations::get_given_value()
{
	return (_given_value);
}

void Operations::set_given_value(double new_value)
{
	_given_value = new_value;
}

void Operations::set_type(std::string oper_type)
{
	_oper_type = oper_type;
}

////////////////////////////////// MULTIPLY CLASS (CHILD) /////////////////////////////////////

Multiply::Multiply(double given_value, double factor) : Operations(given_value)
{
	_factor = factor;
	set_type("Multiplication");
}

void Multiply::execute_function()
{
	double given = get_given_value();
	double new_val = given * _factor;
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

////////////////////////////////// DIVIDE CLASS (CHILD) /////////////////////////////////////

Divide::Divide(double given_value, double divisor) : Operations(given_value)
{
	_divisor = divisor;
}

void Divide::execute_function()
{
	double given = get_given_value();
	double new_val = given / _divisor;
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

////////////////////////////////// ADDITION CLASS (CHILD) /////////////////////////////////////

Addition::Addition(double given_value, double add_value) : Operations(given_value)
{
	_add_value = add_value;
}

void Addition::execute_function()
{
	double given = get_given_value();
	double new_val = given + _add_value;
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

////////////////////////////////// REMOVE LAST VAL CLASS (CHILD) ///////////////////////////////

Remove_last_val::Remove_last_val(double given_value) : Operations(given_value) {}

void Remove_last_val::execute_function()
{
	double value = get_given_value();
	double new_value = remove_last_value(value);
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

////////////////////////////////// ADD LAST VAL CLASS (CHILD) ///////////////////////////////

Add_last_val::Add_last_val(double given_value, double add_value) : Operations(given_value)
{
	_add_value = add_value;
}

void Add_last_val::execute_function()
{
	double value = get_given_value();
	double add_val = _add_value;
	double new_value = add_to_end_of_value(value, add_val);
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

////////////////////////////////// ADD LAST VAL CLASS (CHILD) ///////////////////////////////

Reverse_order::Reverse_order(double given_value) : Operations(given_value) 
{
	set_type("Reverse Order");
}

void Reverse_order::execute_function()
{
	double given_value = get_given_value();
	std::string given_value_string = convert_to_string(given_value);
	std::reverse(given_value_string.begin(), given_value_string.end());
	given_value = convert_to_double(given_value_string);	
	set_given_value(given_value);

}