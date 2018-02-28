// operator_classes.h
// Written by Kasey Barrington, kgbarrington@gmail.com

#pragma once
#ifndef _operator_classes_h
#define _operator_classes_h

#include <string>

/*
*   Parent class of math operations available to the user.
*/
class Operations {
public:
    Operations(int given_value);
    
    virtual void execute_function();
    virtual std::string get_function_type();
    virtual void print_operation_type();
    
    int get_given_value();
    void set_given_value(int new_value);
    void set_type(std::string oper_type);
    
    
private:
    int _given_value;
    std::string _oper_type;

};

/*
*   This class handles multiplication operations.
*/
class Multiply : public Operations
{
public:
    Multiply(int given_value, int factor);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();
    
private:
    int _factor;
    
};

/*
*   This class handles division operations.
*   TODO: Handle false pisitives, by checking if value%divisor == 0
*/
class Divide : public Operations
{
public:
    Divide(int given_value, int divisor);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();
    
private:
    int _divisor;
    
};

/*
*   This class handles addition operations.
*/
class Addition : public Operations
{
public:
    Addition(int given_value, int add_value);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();
    
private:
    int _add_value;
    
};

/*
*   This class handles removing the last digit from a number.
*   Example: Remove last digit from 423 -> 42.
*/
class Remove_last_val : public Operations
{
public:
    Remove_last_val(int given_value);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();

};

/*
*   This class handles adding a digit to the end of a number.
*   Example: add 2 to the end of 4 -> 42.
*/
class Add_last_val : public Operations
{
public:
    Add_last_val(int given_value, int add_value);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();

private:
    int _add_value;
    
};

/*
*   This class handles reversing the order of digits.
*   Example: reverse 24 -> 42.
*/
class Reverse_order : public Operations
{
public:
    Reverse_order(int given_value);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();
};
#endif