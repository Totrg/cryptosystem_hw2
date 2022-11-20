#include "Header.h"

int main(int argc, const char* argv[]) {
	if (argc != 5) {
		std::cerr << "Error: Use five parameters:\n1. the path of executable file\n2. password(positive integer in [0;2147483647])\n3. mode(enc or dec)\n4. the path of the .txt file where the text will be taken from(instead of \"\\\" use \"\\\\\")\n5. the path of the .txt file in which the result will be written(instead of \"\\\" use \"\\\\\")\n";
		return 1;
	}
	const std::string password_str(argv[1]);
	const std::string mode(argv[2]);
	const std::string read_file_name(argv[3]);
	const std::string write_file_name(argv[4]);
	unsigned int password;
	try {
		int res = stoi(password_str);
		password = (unsigned int)res;
	}
	catch (std::invalid_argument e) {
		std::cerr << "Error: Invalid password format\n";
		return 3;
	}
	std::cout << password << std::endl;
	if (mode == "enc")
		encryption(password, read_file_name, write_file_name);
	else if (mode == "dec")
		decryption(password, read_file_name, write_file_name);
	else {
		std::cerr << "Error: assigned mode does not exist \n";
		return 2;
	}
	return 0;
}
