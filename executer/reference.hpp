#ifndef reference_hpp
#define reference_hpp

#include "object.h"

class reference {
public:
	reference(object* _ref_object) : ref_object(_ref_object), counter(1) {};
	
	void inc_counter() {
		counter++;
	};
	
	void dec_counter() {
		counter--;
	};
	
private:
	unsigned int counter;
	object* ref_object;
};

#endif