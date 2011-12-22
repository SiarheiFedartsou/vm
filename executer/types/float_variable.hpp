#ifndef float_variable_hpp
#define float_variable_hpp

#include "arithmetic_variable.hpp"
#include "integer_variable.hpp"

class float_variable : public arithmetic_variable<double> {
public:
	
	float_variable(double _value) : arithmetic_variable<double>(_value) {};
	
	std::string to_string() {
		char buffer[1 << 4];
		sprintf(buffer, "%f", value);
		return buffer;
	};
	
	VARIABLE_TYPE get_type() {
		return FLOAT;
	};
	
	
	virtual bool is_arithmetic() {
		return true;
	}
};

#endif