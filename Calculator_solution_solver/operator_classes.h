// operator_classes.h
// Contains all classes that are used to handle user operation selection.

#pragma once
#ifndef _operator_classes_h
#define _operator_classes_h

#include <string>

class Operations {
public:
    Operations(double given_value);
    
    virtual void execute_function();
    virtual std::string get_function_type();
    virtual void print_operation_type();
    
    double get_given_value();
    void set_given_value(double new_value);
    void set_type(std::string oper_type);
    
    
private:
    double _given_value;
    std::string _oper_type;

};


class Multiply : public Operations
{
public:
    Multiply(double given_value, double factor);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();
    
private:
    double _factor;
    
};

class Divide : public Operations
{
public:
    Divide(double given_value, double divisor);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();
    
private:
    double _divisor;
    
};

class Addition : public Operations
{
public:
    Addition(double given_value, double add_value);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();
    
private:
    double _add_value;
    
};

class Remove_last_val : public Operations
{
public:
    Remove_last_val(double given_value);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();

};

class Add_last_val : public Operations
{
public:
    Add_last_val(double given_value, double add_value);
    void execute_function();
    std::string get_function_type();
    void print_operation_type();

private:
    int _add_value;
    
};

class Reverse_order : public Operations
{
public:
    Reverse_order(double given_value);
    void execute_function();
};
#endif