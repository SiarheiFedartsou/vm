#ifndef CODE_EXECUTER_HPP
#define CODE_EXECUTER_HPP

#include <stack>
#include <map>
#include "object.hpp"
#include "types/integer_variable.hpp"
#include "types/string_variable.hpp"
#include "types/float_variable.hpp"


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

// PUSH
const uint8_t PUSH_ICONST = 0x01;
const uint8_t PUSH_FCONST = 0x02;
const uint8_t PUSH_BCONST = 0x03;
const uint8_t PUSH_UFCONST = 0x04;
const uint8_t PUSH_UICONST = 0x05;
const uint8_t PUSH_SCONST = 0x06;
const uint8_t PUSH_LCONST = 0x07;


// POP
const uint8_t POP = 0x09;

// arithmetic commands
const uint8_t ADD = 0x0A; 
const uint8_t MUL = 0x0B;
const uint8_t SUB = 0x0C;
const uint8_t DIV = 0x0D;

// LOAD/STORE
const uint8_t LOAD_IVAR = 0x0E;
const uint8_t STORE_IVAR = 0x0F;
const uint8_t LOAD_FVAR = 0x10;
const uint8_t STORE_FVAR = 0x11;
const uint8_t LOAD_BVAR = 0x12;
const uint8_t STORE_BVAR = 0x13;
const uint8_t LOAD_UFVAR = 0x14;
const uint8_t STORE_UFVAR = 0x15;
const uint8_t LOAD_UIVAR = 0x16;
const uint8_t STORE_UIVAR = 0x17;
const uint8_t LOAD_SVAR = 0x18;
const uint8_t STORE_SVAR = 0x19;
const uint8_t LOAD_LVAR = 0x1A;
const uint8_t STORE_LVAR = 0x1B;


const uint8_t PRN = 0x1C;
const uint8_t INPUT_I = 0x1D;

class code_executer {
public:
	void execute_code() {
		char code[] = {	PUSH_FCONST, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, // PUSH_ICONST 17 (0x11 == 17)
					    PUSH_FCONST, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, // PUSH_ICONST 4
						
					   	ADD,  // ADD_I
						PUSH_FCONST, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, // PUSH_ICONST 4
						MUL,
						PUSH_FCONST, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, // PUSH_ICONST 4
						DIV,
						PUSH_FCONST, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x40, // PUSH_ICONST 4
						SUB,
						
						PRN
					   };
	//	std::string s(code, 11);
		/*			double v = 3.0f;
					FILE* f = fopen("test", "w");
					fwrite(&v, 1, sizeof(v), f);
					fclose(f);
		std::cout << sizeof(double) << std::endl;
		printf("%x", 1.0f);
	*/	
		code_buffer buffer(code, sizeof(code));
		
		
		while (buffer.can_read()) {
			uint8_t command = buffer.get_uint8();
			
			switch (command) {
				case PUSH_ICONST: {
					int32_t op = buffer.get_int32();
					integer_variable* v = new integer_variable(op);
					stack.push(v);
				}
				break;
				case PUSH_FCONST: {
					double op = buffer.get_double();
					float_variable* v = new float_variable(op);
					stack.push(v);
				}
				break;
				
				case ADD: {
					
					arithmetic_variable_interface* first_op = get_arithmetic_variable_from_stack();
					stack.pop();
					
					arithmetic_variable_interface* second_op = get_arithmetic_variable_from_stack();
					
					second_op->add(first_op);
					
					delete first_op;
				}
				break;
				
				case MUL: {
					arithmetic_variable_interface* first_op = get_arithmetic_variable_from_stack();
					stack.pop();
					
					arithmetic_variable_interface* second_op = get_arithmetic_variable_from_stack();
					
					second_op->multiply(first_op);
					
					delete first_op;
				}
				break;
				
				case DIV: {
					arithmetic_variable_interface* first_op = get_arithmetic_variable_from_stack();
					stack.pop();
					
					arithmetic_variable_interface* second_op = get_arithmetic_variable_from_stack();
					
					second_op->divide(first_op);
					
					delete first_op;
				}
				break;
				
				case SUB: {
					arithmetic_variable_interface* first_op = get_arithmetic_variable_from_stack();
					stack.pop();
					
					arithmetic_variable_interface* second_op = get_arithmetic_variable_from_stack();
					
					second_op->substract(first_op);
					
					delete first_op;
				}
				break;
				
				case POP: {
					if (!stack.empty()) {
						delete stack.top();
						stack.pop();		
					} else {
						std::cerr << "WARNING: cannot pop from empty stack" << std::endl;
					}
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
				
				case INPUT_I: {
					int32_t value;
					std::cin >> value;
					
					stack.push(new integer_variable(value));
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
			
		//	std::cout << "COMMAND " << (uint64_t)command << std::endl;
			
			
		}
		
		std::cout << std::endl << "STACK" << std::endl;
		
		if (!stack.empty()) {
			std::cout << stack.top()->to_string();	
		}
		
		
		std::cout << std::endl << std::endl << "LOCALS" << std::endl;
		
		for (std::map<uint32_t, variable*>::iterator local = locals.begin(); local != locals.end(); ++local) {
			std::cout << local->first << " " << local->second->to_string() << std::endl;
		}	
	}
private:
	
	arithmetic_variable_interface* get_arithmetic_variable_from_stack() {
		if (stack.top()->is_arithmetic()) {
			return (arithmetic_variable_interface*)stack.top();
		} else {
			throw unexpected_type_error();
		}
	}
	
	void execute_push_command(uint8_t command) {
		switch (command) {
			
		}
	}
	
	std::stack<variable*> stack;
	std::map<uint32_t, variable*> locals;
};

#endif