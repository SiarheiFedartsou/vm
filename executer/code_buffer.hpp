#ifndef CODE_BUFFER_HPP
#define CODE_BUFFER_HPP

#include <string>
#include <iostream>
class code_buffer {
public:
	code_buffer(char* _data, size_t length) {
		data = new char[length];
		memcpy(data, _data, length);
		
		data_ptr = data;
		data_length = length;
	};
	
	bool can_read() {
		return data + data_length > data_ptr;
	}
	
	uint32_t get_uint32() {
		uint32_t result = *(uint32_t*)data_ptr;
		data_ptr += sizeof(uint32_t);
		return result;
	}
	
	int32_t get_int32() {
		int32_t result = *(int32_t*)data_ptr;
		data_ptr += sizeof(int32_t);
		return result;
	}
	
	
	
	uint8_t get_uint8() {
		uint8_t result = *(uint8_t*)data_ptr;
		data_ptr += sizeof(uint8_t);
		return result;
	}
	
	std::string get_string() {
		char string_buffer[512];
		//string_buffer[0] = *data_ptr++;
		for (size_t idx = 0; (*data_ptr != '\0'); data_ptr++, idx++) {
			string_buffer[idx] = *data_ptr;
		}
		data_ptr++;
		return string_buffer;
	}
	
	~code_buffer() {
		delete[] data;
	}
private:
	char* data;
	char* data_ptr;
	size_t data_length;
	
};

#endif