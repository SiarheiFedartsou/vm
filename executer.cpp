#include <iostream>
#include <fstream>
#include <stack>
#include <map.h>
#include <stdio.h>
// commands

const char PUSH_8 = 0x01;
const char PUSH_16 = 0x02;
const char PUSH_32 = 0x03;

const char ADD = 0x04;
const char SUB = 0x05;
const char MUL = 0x06;
const char DIV = 0x07;

const char DEFINE_VARIABLE = 0x08;

const char TYPE_STR = 0x01;
const char TYPE_INT = 0x02;
const char TYPE_UINT = 0x03;
const char TYPE_REAL = 0x04;
const char TYPE_UREAL = 0x05;

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


int main(int argc, char const *argv[])
{
	std::stack<uint64_t> stack;
	std::ifstream f_stream("program");
	
	while (!f_stream.eof()) {
		char c = '\0';
		f_stream.get(c);
	
		switch (c) {
			case PUSH_8:
				f_stream.get(c);
				stack.push(c);
				break;
			case PUSH_16:
				{
					uint16_t v = 0;
					f_stream.read((char *)&v, sizeof(v));
					stack.push(v);
				}
				break;
			case PUSH_32:
				{	
					uint32_t v = 0;
					f_stream.read((char *)&v, sizeof(v));
					stack.push(v);
					
				}
				break;
			case ADD:
				{
					uint64_t op_1 = stack.top();
					stack.pop();
					uint64_t op_2 = stack.top();
					stack.pop();
					stack.push(op_1 + op_2);
					
				}
				break;
			case SUB:
				{
					uint64_t op_1 = stack.top();
					stack.pop();
					uint64_t op_2 = stack.top();
					stack.pop();
					stack.push(op_1 - op_2);
				}
				break;
			case MUL:
				{
					uint64_t op_1 = stack.top();
					stack.pop();
					uint64_t op_2 = stack.top();
					stack.pop();
					stack.push(op_1 * op_2);
				}
				break;
			case DIV:
				{
					uint64_t op_1 = stack.top();
					stack.pop();
					uint64_t op_2 = stack.top();
					stack.pop();
					stack.push(op_1 / op_2);
				}
				break;
			case DEFINE_VARIABLE:
				{
					
				}
				break;
		}
	}
	std::cout << stack.top() << std::endl;
	return 0;
}