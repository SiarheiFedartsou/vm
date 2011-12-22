#ifndef integer_variable_hpp
#define integer_variable_hpp

#include "../variable.hpp"

#include "arithmetic_variable.hpp"

class integer_variable : public arithmetic_variable<int32_t> {
public:
	
	integer_variable(int32_t _value) : arithmetic_variable<int32_t>(_value) {};
	
	std::string to_string() {
		char buffer[1 << 4];
		sprintf(buffer, "%d", value);
		return buffer;
	};
	
	VARIABLE_TYPE get_type() {
		return INTEGER;
	};
	
	
	virtual bool is_arithmetic() {
		return true;
	}
};

#endif