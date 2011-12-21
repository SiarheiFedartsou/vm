#ifndef variable_hpp
#define variable_hpp

#include <iostream>
#include "object.hpp"

enum VARIABLE_TYPE {
	UINTEGER,
	INTEGER,
	UFLOAT,
	FLOAT,
	STRING,
	BYTE,
	LIST
};

class variable : public object  {
public:
	virtual VARIABLE_TYPE get_type() = 0;
	virtual bool is_comparable(variable* v) = 0;
	virtual bool is_addable(variable* v) = 0;
	virtual variable* plus(variable*) = 0;
	
	virtual ~variable() {
		
	}
};



#endif