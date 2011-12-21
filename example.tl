module example;

def hello(first_name : string, last_name : string, n : integer) : string {
	var line : string = 'Hello, ';
	line += name + ' ' + last_name;
	
	var result : string;
	
	
	foreach x in range(n) {
		result += x + ' XoX ';
	}
	
	return result;
};

def alloc_n(n : uinteger) {
	var buf : byte = alloc n;
	
	foreach x in buf {
		x = 0;
	}
};

def fibonacci(n : uinteger) : list {
	if n == 0 {
		return null;
	} else if n == 1 {
		return [1];
	} else if n == 2 {
		return [1 1];
	} else {
		var result : list = [1 1];
		
		while n > 2 {
			append_list(result, result[-1] + result[-2]);
			n -= 1;
		}
		
		return result;
	}
};

print hello('Petya', 'Ivanov', 10);