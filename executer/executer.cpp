#include <iostream>
#include <fstream>
#include <stack>
#include <map>
#include <stdio.h>

//#include "variable.hpp"
//#include "types/integer_variable.hpp"
// commands

//const char PUSH_I = 0x01;
//const char PUSH_16 = 0x02;
//const char PUSH_32 = 0x03;
#include "code_executer.hpp"
/*
struct variable {
	unsigned int id;
};

struct string_variable : variable {
	char* var;
};

struct integer_variable : variable {
public:
	integer_variable(signed int _var) : var(_var) {};
	signed int var;
};

struct uinteger_variable : variable {
	unsigned int var;
};

struct real_variable : variable {
	double var;
};

struct ureal_variable : variable {
	double var;
};

std::map<unsigned int, variable*> variables;


void declare_variable(std::ifstream& f_stream, variable*& v) 
{
	char type = '\0';
	f_stream.get(type);
	
	switch (type) {
		case TYPE_INT:
		{
			signed int var = 0;
			f_stream.read((char*)var, sizeof(var));
			
			v = new integer_variable(var);
		}
	}
}
*/
#include <sstream>
int main(int argc, char const *argv[])
{
//	char code[] = {0x01, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x02};
	std::istringstream s("dd");
	code_executer c;
	c.execute_code();

	return 0;
}