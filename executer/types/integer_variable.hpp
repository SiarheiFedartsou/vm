#ifndef integer_variable_hpp
#define integer_variable_hpp

#include "../variable.hpp"

class integer_variable : public variable {
public:
	
	integer_variable(int64_t _value) : value(_value) {};
	
	std::string to_string() {
		char buffer[1 << 4];
		sprintf(buffer, "%d", value);
		return buffer;
	};
	
	VARIABLE_TYPE get_type() {
		return INTEGER;
	};
	
	bool is_comparable(variable* v) {
		switch (v->get_type()) {
			case UINTEGER:
			case INTEGER:
			case UFLOAT:
			case FLOAT:
			case BYTE:
			return true;
			default:
			return false;
		}
	}
	
	bool is_addable(variable* v) {
		switch (v->get_type()) {
			case UINTEGER:
			case INTEGER:
			case UFLOAT:
			case FLOAT:
			case BYTE:
			return true;
			default:
			return false;
		}	
	}
	
	virtual variable* plus(variable* op) {
		if (op->get_type() == INTEGER) {
			return new integer_variable(((integer_variable*)op)->value + this->value);
		} else {
			return new integer_variable(0);
		}
	}
	
	virtual ~integer_variable() {
		
	}
private:
	int32_t value;
};

#endif