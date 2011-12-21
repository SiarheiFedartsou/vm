#ifndef FUNCTION_EXECUTER_HPP
#define FUNCTION_EXECUTER_HPP

#include <map>

#include "function.hpp"

class function_executer {
public:
	void add_function(function f);
	void execute_function(int identifier);
private:	
	std::map<int, function> functions;
};

#endif