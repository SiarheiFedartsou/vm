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
	
	virtual bool is_arithmetic() {
		return false;
	}
	
	virtual ~variable() {
		
	}
};



#endif