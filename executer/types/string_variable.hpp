#ifndef string_variable_hpp
#define string_variable_hpp

#include "../variable.hpp"

class string_variable : public variable {
public:
	
	string_variable(std::string _value) : value(_value) {};
	
	std::string to_string() {
		return value;
	};
	
	VARIABLE_TYPE get_type() {
		return STRING;
	};
	
	bool is_comparable(variable* v) {
		return false;
	}
	
	bool is_addable(variable* v) {
		return false;
	}
	
	
	virtual ~string_variable() {
		
	}
private:
	std::string value;
};

#endif