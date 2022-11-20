#ifndef INCLUDE_HEADER_H_
#define INCLUDE_HEADER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

void encryption(const unsigned int& password, const std::string& read_file_name, const std::string& write_file_name);
void decryption(const unsigned int& password, const std::string& read_file_name, const std::string& write_file_name);


#endif  // INCLUDE_HEADER_H_
