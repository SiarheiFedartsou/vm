#ifndef arithmetic_variable_interface_hpp
#define arithmetic_variable_interface_hpp

#include "../variable.hpp"

class arithmetic_variable_interface : public variable {
public:
	
	virtual bool is_comparable(arithmetic_variable_interface* v) = 0;
	
	virtual bool is_addable(arithmetic_variable_interface* v) = 0;
	virtual void add(arithmetic_variable_interface* op) = 0;
	virtual bool is_multipliable(arithmetic_variable_interface* v) = 0;
	virtual void multiply(arithmetic_variable_interface* op) = 0;
	virtual bool is_substractable(arithmetic_variable_interface* v) = 0;
	virtual void substract(arithmetic_variable_interface* op) = 0;
	virtual bool is_dividable(arithmetic_variable_interface* v) = 0;
	virtual void divide(arithmetic_variable_interface* op) = 0;

};

#endif