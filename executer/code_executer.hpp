#ifndef CODE_EXECUTER_HPP
#define CODE_EXECUTER_HPP

#include <stack>
#include <map>
#include "object.hpp"
#include "types/integer_variable.hpp"
#include "types/string_variable.hpp"

#include <iostream>
#include <sstream>
#include <exception>

#include "code_buffer.hpp"

class code_executer_exception : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Code Executer Error";
	}
};

class unexpected_type_error : public code_executer_exception {
public:
};

const uint8_t PUSH_ICONST = 0x01;
const uint8_t ADD_I = 0x02; 
const uint8_t POP_I = 0x03;

const uint8_t LOAD_IVAR = 0x04;
const uint8_t STORE_IVAR = 0x05;

const uint8_t PRN = 0x06;

const uint8_t PUSH_SCONST = 0x07;

class code_executer {
public:
	void execute_code() {
		char code[] = {	0x01, 0x11, 0x00, 0x00, 0x00, // PUSH_ICONST 17 (0x11 == 17)
					   	0x01, 0x04, 0x00, 0x00, 0x00, // PUSH_ICONST 4
					   	0x02,  // ADD_I
					   	0x05, 0x01, 0x00, 0x00, 0x00, // STORE_IVAR 1
						0x04, 0x01, 0x00, 0x00, 0x00, // LOAD_IVAR 1
						0x07, 0x30, 0x31, 0x39, 0x00,
						0x06 // PRN
					   };
	//	std::string s(code, 11);
		
		code_buffer buffer(code, sizeof(code));
	//	std::istringstream st(s);
		
		
	//	st >> command;
		
	//	std::cout << (uint64_t)command << std::endl;
		
		
		while (buffer.can_read()) {
			uint8_t command = buffer.get_uint8();
			
			switch (command) {
				case PUSH_ICONST: {

					int32_t op = buffer.get_int32();
	
					
					integer_variable* v = new integer_variable(op);
					stack.push(v);
				}
				break;
				case ADD_I: {
					variable* op1 = stack.top();
					stack.pop();
				
					variable* op2 = stack.top();
					stack.pop();

					
					if (op1->is_addable(op2)) {
						stack.push(op1->plus(op2));
					} else {
						throw unexpected_type_error();
						//std::cerr << "Error : operands is not addable" << std::endl;
					}
					
					delete op1;
					delete op2;	
				}
				break;
				
				case POP_I: {
					delete stack.top();
					stack.pop();
				}
				break;
				
				case STORE_IVAR: {
				//	std::cout << (uint64_t)command << std::endl;
					uint32_t local_variable_index = buffer.get_uint32();
					
					locals[local_variable_index] = stack.top();
					
					stack.pop();
				}
				break;
				
				case LOAD_IVAR: {
					uint32_t local_variable_index = buffer.get_uint32();
					stack.push(locals[local_variable_index]);
				}
				break;
				
				case PRN: {
					std::cout << stack.top()->to_string();
				}
				break;
				
				case PUSH_SCONST: {
					std::string op = buffer.get_string();
	
					
					string_variable* v = new string_variable(op);
					stack.push(v);
				}
				break;
			};
			
			
			
		//	command = buffer.get_uint8();
			
	//		std::cout << (uint64_t)command << std::endl;
			
			
		}
		
		std::cout << "STACK" << std::endl;
		
		if (!stack.empty()) {
			std::cout << stack.top()->to_string() << std::endl;	
		}
		
		
		std::cout << std::endl << std::endl << "LOCALS" << std::endl;
		
		for (std::map<uint32_t, variable*>::iterator local = locals.begin(); local != locals.end(); ++local) {
			std::cout << local->first << " " << local->second->to_string() << std::endl;
		}
		
		
		
	}
private:
	std::stack<variable*> stack;
	std::map<uint32_t, variable*> locals;
};

#endif