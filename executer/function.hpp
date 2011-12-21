#ifndef FUNCTION_HPP
#define FUNCTION_HPP

class function {
public:
	function(char[] bytecode, uint32_t identifier) {
		
	};
	
	char* get_bytecode();
private:
	uint32_t identifier;
	char* bytecode;
};

#endif