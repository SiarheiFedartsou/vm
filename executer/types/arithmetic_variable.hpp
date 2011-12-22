#ifndef arithmetic_variable_hpp
#define arithmetic_variable_hpp

#include "arithmetic_variable_interface.hpp"

template<typename T>
class arithmetic_variable : public arithmetic_variable_interface {
public:
	
	arithmetic_variable(T _value) : value(_value) {};
	
	bool is_comparable(arithmetic_variable_interface* v) {
		return this->get_type() == v->get_type();
	}
	
	bool is_addable(arithmetic_variable_interface* v) {
		return this->get_type() == v->get_type();
	}
	
	void add(arithmetic_variable_interface* op) {
		this->value += get_second_operand_value(op);
	}
	
	bool is_multipliable(arithmetic_variable_interface* v) {
		return this->is_addable(v);
	}
	
	void multiply(arithmetic_variable_interface* op) {
		this->value *= get_second_operand_value(op);
	};
	
	virtual bool is_substractable(arithmetic_variable_interface* v) {
		return this->is_addable(v);
	}
	
	virtual void substract(arithmetic_variable_interface* op) {
		this->value -= get_second_operand_value(op);
	}
	
	virtual bool is_dividable(arithmetic_variable_interface* v) {
		return this->is_addable(v);
	}
	
	virtual void divide(arithmetic_variable_interface* op) {
		this->value /= get_second_operand_value(op);
	}
	
	
	virtual ~arithmetic_variable() {
		
	}
	
	T get_value() {
		return value;
	}
protected:
	
	T get_second_operand_value(arithmetic_variable_interface* second_operand) {
		return ((arithmetic_variable<T>*)second_operand)->get_value();
	}
	
	T value;
};

#endif