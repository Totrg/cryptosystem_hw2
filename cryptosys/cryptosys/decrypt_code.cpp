#include "Header.h"

void decryption(const unsigned int& password, const std::string& read_file_name, const std::string& write_file_name) {
	srand(password);
	std::string str, tmp, rez;
	std::ifstream read_file(read_file_name, std::ios_base::in);
	if (read_file.is_open()) while (getline(read_file, tmp)) str+=tmp;
	read_file.close();
	for (int i = 0; i < str.size() / 2; i++) {
		std::bitset<16> block(std::bitset<8>(str[i * 2]).to_string() + std::bitset<8>(str[i * 2 + 1]).to_string());
		int r = rand();
		auto gamma = std::bitset<16>(r);
		block = block ^ gamma;
		block = (block >> 1 | block << 15);
		std::bitset<8> curbitset(0);
		unsigned char symb1, symb2;
		for (int i = 0; i < 16; i++) {
			if (i < 8) curbitset[i] = block[i];
			else if (i == 8) {
				symb1 = static_cast<unsigned char>(curbitset.to_ulong());
				curbitset[i - 8] = block[i];
			}
			else if (i < 15) curbitset[i - 8] = block[i];
			else
			{
				curbitset[i - 8] = block[i];
				symb2 = static_cast<unsigned char>(curbitset.to_ulong());
			}
		}
		rez += symb2; rez += symb1;
	}
	std::ofstream write_file(write_file_name, std::ios_base::out | std::ios_base::trunc);
	write_file.write(rez.c_str(), rez.size());
	write_file.close();
	std::cout << "--the result was entered in " << write_file_name <<"--\n";
	std::cout << "--completed successfully--\n";
}